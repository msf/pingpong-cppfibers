use anyhow::Result;
use clap::Parser;
use futures::Stream;
use proto::pingpong::ping_pong_server::{PingPong, PingPongServer};
use proto::pingpong::{Ping, Pong};
use std::pin::Pin;
use tokio::time::{sleep, Duration};
use tonic::{transport::Channel, transport::Server, Request, Response, Status, Streaming};

#[derive(Parser)]
struct Opts {
    #[clap(long, default_value = "/tmp/pingpong.sock")]
    socket: String,

    #[clap(long)]
    sleep: bool,

    #[clap(long, default_value = "2")]
    threads: usize,
}

pub struct PingPongService {
    sleep: bool,
}

#[tonic::async_trait]
impl PingPong for PingPongService {
    type StreamPingPongStream = Pin<Box<dyn Stream<Item = Result<Pong, Status>> + Send>>;

    async fn stream_ping_pong(
        &self,
        request: Request<Streaming<Ping>>,
    ) -> Result<Response<Self::StreamPingPongStream>, Status> {
        let mut in_stream = request.into_inner();
        let sleep_enabled = self.sleep;

        // Create a stream handler that processes one message at a time
        let out_stream = Box::pin(async_stream::try_stream! {
            while let Some(ping) = in_stream.message().await? {
                // Optional sleep to simulate work
                if sleep_enabled {
                    sleep(Duration::from_micros(10)).await;
                }

                // Process exactly one message and send response
                let pong = Pong {
                    sequence: ping.sequence,
                    timestamp: ping.timestamp,
                    server_timestamp: std::time::SystemTime::now()
                        .duration_since(std::time::UNIX_EPOCH)
                        .unwrap()
                        .as_nanos() as u64,
                    payload: ping.payload,
                };

                yield pong;
            }
        });

        Ok(Response::new(out_stream))
    }
}

#[tonic::async_trait]
impl PingPong for PingPongService {
    type StreamPingPongStream = Pin<Box<dyn Stream<Item = Result<Pong, Status>> + Send>>;

    async fn stream_ping_pong(
        &self,
        request: Request<Streaming<Ping>>,
    ) -> Result<Response<Self::StreamPingPongStream>, Status> {
        let mut in_stream = request.into_inner();
        let sleep_enabled = self.sleep;

        let out_stream = async_stream::try_stream! {
            while let Some(ping) = in_stream.message().await? {
                if sleep_enabled {
                    sleep(Duration::from_micros(10)).await;
                }

                yield Pong {
                    sequence: ping.sequence,
                    timestamp: ping.timestamp,
                    server_timestamp: std::time::SystemTime::now()
                        .duration_since(std::time::UNIX_EPOCH)
                        .unwrap()
                        .as_nanos() as u64,
                    payload: ping.payload,
                };
            }
        };

        Ok(Response::new(Box::pin(out_stream)))
    }
}

#[tokio::main]
async fn main() -> Result<()> {
    let opts = Opts::parse();

    let runtime = tokio::runtime::Builder::new_multi_thread()
        .worker_threads(opts.threads)
        .enable_all() // IO, time, etc
        .thread_name("pingpong-worker")
        .build()?;

    runtime.block_on(async {
        let service = PingPongService { sleep: opts.sleep };

        let sock_path = format!("unix://{}", opts.socket);
        let addr = sock_path.parse()?;

        println!("Server listening on {}", sock_path);

        let msg_size = 16 * 1024;
        Server::builder()
            //.tcp_nodelay(true)
            //.tcp_keepalive(None)
            .initial_stream_window_size(msg_size)
            .initial_connection_window_size(msg_size)
            .max_concurrent_streams(1024)
            .http2_keepalive_interval(None) // Disable keepalive
            .add_service(PingPongServer::new(service))
            .serve(addr)
            .await?;

        Ok(())
    })
}
