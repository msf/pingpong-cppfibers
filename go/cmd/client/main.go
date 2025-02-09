package main

import (
	"context"
	"log"
	"time"

	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
	pb "pingpong/pkg/proto/pingpong"
)

func main() {
	// Basic connection without optimizations
	conn, err := grpc.Dial(
		"localhost:50051",
		grpc.WithTransportCredentials(insecure.NewCredentials()),
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
	start := time.Now()

	// Basic send loop
	seq := uint64(0)
	for {
		ping := &pb.Ping{
			Sequence:  seq,
			Timestamp: uint64(time.Now().UnixNano()),
		}
		if err := stream.Send(ping); err != nil {
			log.Printf("Send error: %v", err)
			break
		}
		seq++
		_, err := stream.Recv()
		if err != nil {
			log.Printf("Receive error: %v", err)
			return
		}
		count++

		if seq%100000 == 0 {
			elapsed := time.Since(start).Seconds()
			log.Printf("Messages/sec: %.2f", float64(count)/elapsed)
		}

	}
}
