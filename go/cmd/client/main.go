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

func main() {
	payloadSize := flag.Int("payload", 0, "Payload size in bytes")
	flag.Parse()

	// Pre-generate payload of specified size
	payload := make([]byte, *payloadSize)
	for i := range payload {
		payload[i] = byte(i % 256)
	}

	// Basic connection without optimizations
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

	client := pb.NewPingPongClient(conn)
	stream, err := client.StreamPingPong(context.Background())
	if err != nil {
		log.Fatalf("Failed to create stream: %v", err)
	}

	// Simple counter
	count := 0
	var bytesTransferred uint64
	start := time.Now()

	// Basic send loop
	seq := uint64(0)
	for {
		ping := &pb.Ping{
			Sequence:  seq,
			Timestamp: uint64(time.Now().UnixNano()),
			Payload:   payload,
		}
		if err := stream.Send(ping); err != nil {
			log.Printf("Send error: %v", err)
			break
		}
		seq++
		pong, err := stream.Recv()
		if err != nil {
			log.Printf("Receive error: %v", err)
			return
		}
		count++
		bytesTransferred += 128 + uint64(len(pong.Payload))

		if seq%100000 == 0 {
			elapsed := time.Since(start).Seconds()
			msgRate := float64(count) / elapsed
			bytesRate := float64(bytesTransferred) / elapsed / 1024 / 1024 // MB/s
			log.Printf("Msgs/sec: %.2f, Throughput: %.2f MB/s", msgRate, bytesRate)
		}

	}
}
