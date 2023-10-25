package main;

import com.google.protobuf.Timestamp;
import org.apache.kafka.clients.producer.KafkaProducer;
import org.apache.kafka.clients.producer.Producer;
import org.apache.kafka.clients.producer.ProducerConfig;
import org.apache.kafka.clients.producer.ProducerRecord;
import org.apache.kafka.common.serialization.StringSerializer;
import protobuf.LogMessageOuterClass;
import serializer.ProtobufSerializer;

import java.util.Date;
import java.util.Properties;
import java.util.Random;

public class JavaProducer {

    public static void main(String[] args) throws InterruptedException {
        Properties props = new Properties();
        props.put(ProducerConfig.BOOTSTRAP_SERVERS_CONFIG, ":9092");
        props.put(ProducerConfig.KEY_SERIALIZER_CLASS_CONFIG, StringSerializer.class.getName());
        props.put(ProducerConfig.VALUE_SERIALIZER_CLASS_CONFIG, ProtobufSerializer.class.getName());

        Producer<String, LogMessageOuterClass.LogMessage> producer = new KafkaProducer<>(props);


        int logCount = 0;
        boolean stopCondition = true;

        while(stopCondition) {
            var random = new Random();

            LogMessageOuterClass.LogMessage logMessage = LogMessageOuterClass.LogMessage.newBuilder()
                    .setTimestamp(getTimestamp())
                    .setLogLevelValue(random.nextInt(4))
                    .setMessage("Java Producer")
                    .build();

            ProducerRecord<String, LogMessageOuterClass.LogMessage> record = new ProducerRecord<>("event", logMessage);
            producer.send(record);
            logCount++;
            stopCondition = logCount < Integer.MAX_VALUE;
            Thread.sleep(3000);
        }

        producer.close();
    }

    private static Timestamp getTimestamp() {
        Timestamp timestamp;
        Date date;

        date = new Date();
        timestamp = Timestamp.newBuilder()
                .setSeconds(date.getTime() / 1000)
                .setNanos((int) ((date.getTime() % 1000) * 1000000))
                .build();
        return timestamp;
    }

}