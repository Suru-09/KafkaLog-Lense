use opentelemetry::{global, metrics::Unit, KeyValue};
use opentelemetry_sdk::metrics::{PeriodicReader, SdkMeterProvider};
use opentelemetry_sdk::{runtime, Resource};
use sysinfo::{System};
use std::error::Error;
use std::time::Duration;
use tokio::time::interval;
use serde::Serialize;
use chrono::Utc;
use reqwest::Client;

pub mod uid_generator;

use crate::uid_generator::init_uid;


#[derive(Serialize, Debug)]
struct MetricsData {
    service: String,
    uuid: String,
    cpu_usage: f64,
    ram_usage: f64,
    timestamp: String,
}

async fn send_metrics_to_elasticsearch(client: &Client, metrics: &MetricsData) -> Result<(), Box<dyn Error>> {
    let res = client.post("http://192.168.1.186:9200/metrics/_doc")
        .json(metrics)
        .send()
        .await?;

    if res.status().is_success() {
        println!("Successfully sent metrics to Elasticsearch: {:?}", metrics);
    } else {
        println!("Failed to send metrics to Elasticsearch: {:?}", res.text().await?);
    }

    Ok(())
}

fn init_meter_provider() -> SdkMeterProvider {
    let exporter = opentelemetry_stdout::MetricsExporterBuilder::default()
        .build();
    let reader = PeriodicReader::builder(exporter, runtime::Tokio).with_interval(Duration::from_secs(5)).build();
    let provider = SdkMeterProvider::builder()
        .with_reader(reader)
        .with_resource(Resource::new(vec![KeyValue::new(
            "resources.metrics",
            "metrics_cpu_ram",
        )]))
        .build();
    global::set_meter_provider(provider.clone());
    provider
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn Error + Send + Sync + 'static>> {
    // Initialize the MeterProvider with the stdout Exporter.
    let meter_provider = init_meter_provider();

    let uid = init_uid();
    if uid.is_err() {
        panic!("Failed to initialize UID");
    }

    let uid_str = uid.unwrap();

    // Create a meter from the above MeterProvider.
    let meter = global::meter("metricsprovider");

    let _cpu_usage_observer = meter
        .f64_observable_gauge("cpu_usage")
        .with_description("CPU usage percentage")
        .with_callback(move |observer| {
            let mut sys = System::new_all();
            sys.refresh_cpu();
            let mut cpu_usage: f64 = 0.0;
            for cpu in sys.cpus() {
                cpu_usage += cpu.cpu_usage() as f64;
            }
            cpu_usage /= sys.cpus().len() as f64;
            observer.observe(cpu_usage, &[]);
        })
        .init();

    let _ram_usage_observer = meter
        .f64_observable_gauge("ram_usage")
        .with_description("RAM usage percentage")
        .with_unit(Unit::new("percentage"))
        .with_callback(move |observer| {
            let mut sys = System::new_all();
            sys.refresh_memory();
            let total_memory = sys.total_memory() as f64;
            let used_memory = sys.used_memory() as f64;
            let ram_usage = (used_memory / total_memory) * 100.0;
            observer.observe(ram_usage, &[]);
        })
        .init();    

    // Simulate periodic recording and exporting of metrics
    let mut interval = interval(Duration::from_secs(3));
    loop {
        interval.tick().await;

        // Refresh system information
        let mut sys = System::new_all();
        let client = Client::new();
        sys.refresh_cpu();
        sys.refresh_memory();

        // Collect metrics
        let mut cpu_usage: f64 = 0.0;
        for cpu in sys.cpus() {
            cpu_usage += cpu.cpu_usage() as f64;
        }
        cpu_usage /= sys.cpus().len() as f64;
        let total_memory = sys.total_memory() as f64;
        let used_memory = sys.used_memory() as f64;
        let ram_usage = (used_memory / total_memory) * 100.0;

        // Create metrics data
        let metrics = MetricsData {
            service: "resources.metrics".to_string(),
            uuid: uid_str.clone(),
            cpu_usage,
            ram_usage,
            timestamp: Utc::now().to_rfc3339(),
        };
        

        // Send metrics to Elasticsearch
        if let Err(e) = send_metrics_to_elasticsearch(&client, &metrics).await {
            eprintln!("Error sending metrics to Elasticsearch: {:?}", e);
        }
    }

    // Metrics are exported by default every 30 seconds when using stdout exporter,
    // however shutting down the MeterProvider here instantly flushes
    // the metrics, instead of waiting for the 30 sec interval.
    meter_provider.shutdown()?;
    Ok(())
}
