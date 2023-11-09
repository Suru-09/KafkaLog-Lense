#include "kafka_producer.h"


namespace kafka {


KafkaProducer::KafkaProducer(const std::string& brokers) 
: m_brokers(brokers) 
{
    std::cout << "KafkaProducer::KafkaProducer()" << std::endl;

    std::string errStr;

    m_conf = std::unique_ptr<RdKafka::Conf>(RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL));

    if (m_conf->set("bootstrap.servers", brokers, errStr) != RdKafka::Conf::CONF_OK) 
    {
        std::cerr << errStr << std::endl;
        exit(1);
    }

    if (m_conf->set("dr_cb", &m_logMessageDeliveredCb, errStr) != RdKafka::Conf::CONF_OK) 
    {
        std::cerr << errStr << std::endl;
        exit(1);
    }
}

void KafkaProducer::produce(const std::string& topic, const protobuf::LogMessage& logMessage)
{
    std::string errStr;
    std::unique_ptr<RdKafka::Producer> producer = 
        std::unique_ptr<RdKafka::Producer>(
            RdKafka::Producer::create(m_conf.get(), errStr)
        );

    if (!producer)
    {
        std::cerr << "Failed to create producer: " << errStr << std::endl;
        exit(1);
    }

    std::unique_ptr<RdKafka::Topic> topicPtr = 
        std::unique_ptr<RdKafka::Topic>(
            RdKafka::Topic::create(producer.get(), topic, NULL, errStr)
        );

    RdKafka::ErrorCode err = producer->produce(
        topicPtr.get(),
        RdKafka::Topic::PARTITION_UA, 
        RdKafka::Producer::RK_MSG_COPY /* Copy payload */,
        const_cast<char*>(logMessage.SerializeAsString().c_str()), 
        logMessage.ByteSizeLong(), 
        NULL, 
        NULL
    );

    if (err != RdKafka::ERR_NO_ERROR)
    {
        std::cerr << "% Produce failed: " << RdKafka::err2str(err) << std::endl;
    }
    else
    {
        std::cerr << "% Produced message (" << logMessage.ByteSizeLong() << " bytes)" << std::endl;
    }

    producer->flush(10 * 1000 /* wait for max 10 seconds */);

}



}