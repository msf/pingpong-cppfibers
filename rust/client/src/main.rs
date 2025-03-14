use clap::Parser;
use futures::StreamExt;
use proto::pingpong::ping_pong_client::PingPongClient;
use proto::pingpong::Ping;
use std::time::Instant;
use tonic::transport::channel::Endpoint;
use tonic::transport::Uri;
use tonic::Request;
use tower::service_fn;

#[derive(Parser)]
struct Opts {
    #[clap(long, default_value = "/tmp/pingpong.sock")]
    socket: String,

    #[clap(long, default_value = "0")]
    payload: usize,

    #[clap(long, default_value = "1")]
    workers: usize,
}

async fn run_worker(id: usize, socket_path: String, payload: Vec<u8>) -> Result<(), anyhow::Error> {
    //let msg_size = 16 * 1024;
    let channel = Endpoint::try_from("http://dummy")?
        .connect_with_connector(service_fn(move |_: Uri| {
            let path = socket_path.clone();
            async move { tokio::net::UnixStream::connect(path).await }
        }))
        .await?;

    let mut client = PingPongClient::new(channel);

    let mut stream = client
        .stream_ping_pong(Request::new(futures::stream::empty()))
        .await?
        .into_inner();

    let mut start = Instant::now();
    let mut count = 0u64;
    let mut bytes = 0u64;

    loop {
        let ping = Ping {
            sequence: count,
            timestamp: std::time::SystemTime::now()
                .duration_since(std::time::UNIX_EPOCH)
                .unwrap()
                .as_nanos() as u64,
            payload: payload.clone(),
        };
        stream.send(ping).await?;

        if let Ok(Some(pong)) = stream.message().await {
            count += 1;
            bytes += 128 + pong.payload.len() as u64;

            if count % 100000 == 0 {
                let elapsed = start.elapsed().as_secs_f64();
                let tps = count as f64 / elapsed;
                let mbps = (bytes as f64 / elapsed) / (1024.0 * 1024.0);
                println!("Worker {}: {:.2} TPS, {:.2} MB/s", id, tps, mbps);
                start = Instant::now();
                count = 0;
                bytes = 0;
            }
        }
    }
}

#[tokio::main]
async fn main() -> Result<(), anyhow::Error> {
    let opts = Opts::parse();

    let payload = vec![0u8; opts.payload];
    let mut handles = Vec::new();

    for id in 0..opts.workers {
        let payload = payload.clone();
        let socket = opts.socket.clone();

        let handle = tokio::spawn(async move {
            if let Err(e) = run_worker(id, socket, payload).await {
                eprintln!("Worker {} error: {}", id, e);
            }
        });

        handles.push(handle);
    }

    futures::future::join_all(handles).await;
    Ok(())
}
