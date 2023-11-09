package main;

import com.google.protobuf.Timestamp;
import utils.Utils;
import org.apache.kafka.clients.producer.KafkaProducer;
import org.apache.kafka.clients.producer.Producer;
import org.apache.kafka.clients.producer.ProducerConfig;
import org.apache.kafka.clients.producer.ProducerRecord;
import org.apache.kafka.common.serialization.StringSerializer;
import org.slf4j.LoggerFactory;
import org.slf4j.Logger;
import protobuf.LogMessageOuterClass.ApplicationLanguage;
import protobuf.LogMessageOuterClass.LogMessage;
import serializer.ProtobufSerializer;

import java.util.Date;
import java.util.Properties;
import java.util.Random;

public class JavaProducer {

    private static final Logger LOGGER = LoggerFactory.getLogger(JavaProducer.class);
    private static final ApplicationLanguage APPLICATION_LANGUAGE = ApplicationLanguage.JAVA;
    private static final String FILE = "producers/java/src/main/resources/uid.json";

    public static void main(String[] args) throws InterruptedException {
        Properties props = new Properties();
        props.put(ProducerConfig.BOOTSTRAP_SERVERS_CONFIG, "192.168.1.186:9094");
        props.put(ProducerConfig.KEY_SERIALIZER_CLASS_CONFIG, StringSerializer.class.getName());
        props.put(ProducerConfig.VALUE_SERIALIZER_CLASS_CONFIG, ProtobufSerializer.class.getName());

        Producer<String, LogMessage> producer = new KafkaProducer<>(props);

        int logCount = 0;
        boolean stopCondition = true;

        while(stopCondition) {
            var random = new Random();

            LogMessage logMessage = LogMessage.newBuilder()
                    .setTimestamp(getTimestamp())
                    .setLogLevelValue(random.nextInt(5))
                    .setMessage("...")
                    .setAppLang(APPLICATION_LANGUAGE)
                    .setUid(Utils.readOrCreateUid(FILE))
                    .build();

            ProducerRecord<String, LogMessage> record = new ProducerRecord<>("event", logMessage);
            producer.send(record);
            LOGGER.info("Sent message: " + logMessage);
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