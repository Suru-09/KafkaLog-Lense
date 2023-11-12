package main

import (
	"crypto/sha256"
	"encoding/hex"
	"encoding/json"
	"fmt"
	"github.com/Shopify/sarama"
	"github.com/golang/protobuf/proto"
	"github.com/golang/protobuf/ptypes"
	"io/ioutil"
	"log"
	"main/main/protobuf"
	"math/rand"
	"time"
)

const (
	CONST_HOST  = "192.168.1.186:9094"
	CONST_TOPIC = "event"
)

type Uid struct {
	Uid string `json:"Uid"`
}

func generateUid(length int) (string, error) {
	bytes := make([]byte, length)
	_, err := rand.Read(bytes)
	if err != nil {
		return "", err
	}
	currentTime := time.Now().Unix()
	randomString := fmt.Sprintf("%s%d", hex.EncodeToString(bytes), currentTime)
	hash := sha256.New()
	hash.Write([]byte(randomString))
	uid := hex.EncodeToString(hash.Sum(nil))
	return uid, nil
}

func getUid() (string, error) {
	var generated_uid string
	var data Uid
	returnData, err := ioutil.ReadFile("uid.json")
	if err != nil {
		generated_uid, _ = generateUid(32)
		data = Uid{
			Uid: generated_uid,
		}
		jsonData, _ := json.MarshalIndent(data, "", " ")
		err = ioutil.WriteFile("uid.json", jsonData, 0644)
	} else {
		err = json.Unmarshal(returnData, &data)
		if err != nil {
			fmt.Println("Error unmarshaling JSON:", err)
			return "", err
		}
	}
	return data.Uid, nil
}

func main() {
	config := sarama.NewConfig()
	config.Producer.Return.Successes = true
	config.Producer.Return.Errors = true
	producer, err := sarama.NewSyncProducer([]string{CONST_HOST}, config)
	if err != nil {
		log.Fatal("Failed to initialize NewSyncProducer, err:", err)
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
		appLang := protobuf.ApplicationLanguage_GO
		nr_gen := rand.Intn(5)
		logLevel := protobuf.LogLevel(nr_gen)
		logMessage := "Go producer"
		uid, err := getUid()
		if err != nil {
			fmt.Println("Error generating uid:", err)
			return
		}
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
		_, _, err = producer.SendMessage(kafkaMessage)
		if err != nil {
			log.Printf("Error sending log: %v\n", err)
		} else {
			fmt.Printf("(nr_gen: %d)Log: %s\n", nr_gen, message)
		}
		time.Sleep(3 * time.Second)
	}
}
