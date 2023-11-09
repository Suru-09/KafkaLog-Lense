#include <iostream>
#include <random>
#include <string>
#include <thread>

#include "uid.h"
#include "utils.h"
#include "kafka_producer.h"
#include "normal_distribution.h"

int main(int argc, char *argv[]) {
    uid::UID uid;
    uid.initUID();
    auto uidStr = uid.getUID();
    
    kafka::KafkaProducer kafkaProducer("192.168.1.186:9094");
    NormalDistribution normalDistribution(2.5, 1.0);
    while(true)
    {
        auto logLevel = normalDistribution.getLogLevelSample();
        std::string message = "This is a message from the CPP producer";
        auto logMessage = utils::createLogMessage(uidStr, 
            message, logLevel, protobuf::ApplicationLanguage::CPP);
        kafkaProducer.produce("event", logMessage);

        // sleep for 3 seconds
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    return 0;
}