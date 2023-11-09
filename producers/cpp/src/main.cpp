#include <iostream>

#include "uid.h"
#include "utils.h"
#include "kafka_producer.h"

int main(int argc, char *argv[]) {
    uid::UID uid;
    uid.initUID();
    auto uidStr = uid.getUID();
    
    kafka::KafkaProducer kafkaProducer("192.168.1.186:9094");
    while(true)
    {
        auto logMessage = utils::createLogMessage(uidStr, 
            "CPP Producer", protobuf::LogLevel::DEBUG, protobuf::ApplicationLanguage::CPP);
        kafkaProducer.produce("event", logMessage);
    }
    return 0;
}