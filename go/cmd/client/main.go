package main

import (
	"context"
	"flag"
	"log"
	"time"

	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
	pb "pingpong/pkg/proto/pingpong"
)

func runWorker(id int, conn *grpc.ClientConn, payloadLen int) {
	client := pb.NewPingPongClient(conn)
	stream, err := client.StreamPingPong(context.Background())
	if err != nil {
		log.Printf("Worker %d stream error: %v", id, err)
		return
	}
	payload := make([]byte, payloadLen)
	for i := range payload {
		payload[i] = byte(i + id%256)
	}

	var count uint64 = 0
	var bytes uint64 = 0
	start := time.Now()

	var ping pb.Ping
	for {
		// Send
		ping.Sequence = count
		ping.Timestamp = uint64(time.Now().UnixNano())
		ping.Payload = payload
		if err := stream.Send(&ping); err != nil {
			log.Printf("Worker %d send error: %v", id, err)
			return
		}

		// Receive
		pong, err := stream.Recv()
		if err != nil {
			log.Printf("Worker %d receive error: %v", id, err)
			return
		}

		count++
		bytes += 128 + uint64(len(pong.Payload))

		// Report every second
		if count%100000 == 0 {
			elapsed := time.Since(start).Seconds()
			tps := float64(count) / elapsed
			mbps := float64(bytes) / elapsed / 1024 / 1024
			log.Printf("Worker %d: %.2f TPS, %.2f MB/s", id, tps, mbps)

			start = time.Now()
			count = 0
			bytes = 0
		}
	}
}

func main() {
	payloadSize := flag.Int("payload", 0, "Payload size in bytes")
	workers := flag.Int("workers", 1, "Number of workers")
	flag.Parse()

	const max_size = 16 * 1024
	conn, err := grpc.Dial(
		"unix:///tmp/pingpong.sock",
		grpc.WithTransportCredentials(insecure.NewCredentials()),
		grpc.WithInitialWindowSize(max_size),
		grpc.WithInitialConnWindowSize(max_size),
		grpc.WithDefaultCallOptions(
			grpc.MaxCallRecvMsgSize(max_size),
			grpc.MaxCallSendMsgSize(max_size),
		),
	)
	if err != nil {
		log.Fatalf("Failed to connect: %v", err)
	}
	defer conn.Close()

	log.Printf("Starting %v clients, payloadSize: %v", *workers, *payloadSize)
	for i := 0; i < *workers; i++ {
		go runWorker(i, conn, *payloadSize)
	}

	select {}
}
