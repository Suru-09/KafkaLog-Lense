#ifndef __KAFKA_PRODUCER_H_
#define __KAFKA_PRODUCER_H_

#include <iostream>
#include <string>
#include <memory>

#include <librdkafka/rdkafkacpp.h>
#include "LogMessage.pb.h"

namespace kafka {

class LogMessageDeliveredCb : public RdKafka::DeliveryReportCb {
public:
    void dr_cb(RdKafka::Message &message) {
        /* If message.err() is non-zero the message delivery failed permanently
            * for the message. */
        if (message.err())
            std::cerr << "% Message delivery failed: " << message.errstr()
                    << std::endl;
        else
            std::cerr << "% Message delivered to topic " << message.topic_name()
                    << " [" << message.partition() << "] at offset "
                    << message.offset() << std::endl;
    }
};

class KafkaProducer {
public:
    explicit KafkaProducer(const std::string& brokers);
    ~KafkaProducer() = default;

    void produce(const std::string& topic, const protobuf::LogMessage& logMessage);
private:
    std::string m_brokers;
    std::unique_ptr<RdKafka::Conf> m_conf;
    LogMessageDeliveredCb m_logMessageDeliveredCb;
};


}   // namespace kafka



#endif // __KAFKA_PRODUCER_H_