package main

import (
	"fmt"
	"github.com/Shopify/sarama"
	"github.com/golang/protobuf/proto"
	"github.com/golang/protobuf/ptypes"
	"log"
	"main/main/protobuf"
	"time"
)

const (
	CONST_HOST  = "192.168.1.186:9094"
	CONST_TOPIC = "event"
)

func main() {
	config := sarama.NewConfig()

	config.Producer.Return.Successes = true
	config.Producer.Return.Errors = true
	producer, err := sarama.NewSyncProducer([]string{CONST_HOST}, config)
	if err != nil {
		log.Fatal("failed to initialize NewSyncProducer, err:", err)
		return
	}
	defer producer.Close()

	for i := 0; i < 1000; i++ {
		now := time.Now()

		protoTimestamp, err := ptypes.TimestampProto(now)
		if err != nil {
			fmt.Println("Error converting time to Timestamp:", err)
			return
		}

		fmt.Println(protoTimestamp)

		appLang := protobuf.ApplicationLanguage_GO

		logLevel := protobuf.LogLevel_DEBUG

		logMessage := "Go producer"

		uid := "abc"

		message := &protobuf.LogMessage{
			Timestamp: protoTimestamp,
			LogLevel:  logLevel,
			Message:   logMessage,
			AppLang:   appLang,
			Uid:       uid,
		}

		data, err := proto.Marshal(message)
		if err != nil {
			fmt.Println("Error marshaling protobuf message:", err)
			return
		}

		kafkaMessage := &sarama.ProducerMessage{
			Topic: CONST_TOPIC,
			Value: sarama.ByteEncoder(data),
		}

		producer.SendMessage(kafkaMessage)

		log.Printf(" %d\n", i)

		time.Sleep(3 * time.Second)
	}
}
