# KafkaLog-Lense

A tool meant to centralize logs from multiple applications, language agnostic.For demonstration purposes we will have multiple producers written in Java, Rust, C++ and Go. The consumer will be written in Rust for performance reasons.

## Application architecture

<img src="docs/overall_arch_v2.svg">

<details>
<summary style="font-size: 173%; font-weight: bold;; padding-top: 30px;">Dependencies and tools used</summary>

### Rust

| Library               | Version    |
|-----------------------|------------|
| rdkafka               | 0.25       |
| tokio                 | 1.33.0     |
| chrono                | 0.4.31     |
| sha256                | 1.4.0      |
| rng                   | 0.1.0      |
| rand                  | 0.8.5      |
| serde_json            | 1.0.108    |
| protobuf              | 2.27.1     |
| protobuf-codegen      | 2.27.1     |
| protoc-rust           | 2.28.0     |
| futures               | 0.3.29     |


### Go

| Library                                 | Version    |
|-----------------------------------------|------------|
| github.com/Shopify/sarama               | 1.38.1     |
| github.com/golang/protobuf              | 1.5.2      |


### C++

| Library                  | Version     |
|--------------------------|-------------|
| librdkafka (rdkafka)     |             |
| OpenSSL                  |             |
| JSON for Modern C++ (nlohmann/json) | 3.11.2      |


### Java

| Library                                    | Artifact                              | Version      |
|--------------------------------------------|---------------------------------------|--------------|
| Apache Kafka Clients                       | org.apache.kafka:kafka-clients       | 3.0.0        |
| SLF4J API                                  | org.slf4j:slf4j-api                   | 1.7.32       |
| SLF4J Simple                               | org.slf4j:slf4j-simple                | 1.7.32       |
| Kafka Log4j Appender                       | org.apache.kafka:kafka-log4j-appender| 3.6.0        |
| Protocol Buffers (Java)                    | com.google.protobuf:protobuf-java    | 3.21.7       |
| Apache Commons Lang                        | org.apache.commons:commons-lang3     | 3.13.0       |
| Gson                                       | com.google.code.gson:gson             | 2.7          |
</details>

## Further improvements

- Consumer Groups: Adding more Kafka consumers to groups to scale the application horizontally.
- Scaling: Create Docker images for the Kafka producers and consumer in order to streamline the process of creating a consumers/producers, thus creating a highly distributed application.
- Error Handling: Implementing robust error handling and retries for Kafka consumers to handle transient issues.
- Throttling: Implementing throttling mechanisms to prevent overwhelming downstream components during bursts of log activity.
- Filtering and Parsing: Implementing filtering mechanisms to discard irrelevant logs and parsing logic to extract structured data from log entries.