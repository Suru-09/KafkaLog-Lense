#include "normal_distribution.h"

NormalDistribution::NormalDistribution(double mean, double stddev)
{
    m_distribution = std::normal_distribution<double>(mean, stddev);
}

protobuf::LogLevel NormalDistribution::getLogLevelSample()
{
    double number = m_distribution(m_generator);
    auto floorNumber = static_cast<int>(number);
    switch(floorNumber % 5)
    {
        case 0:
            return protobuf::LogLevel::DEBUG;
        case 1:
            return protobuf::LogLevel::INFO;
        case 2:
            return protobuf::LogLevel::WARNING;
        case 3:
            return protobuf::LogLevel::ERROR;
        case 4:
            return protobuf::LogLevel::FATAL;
        default:
            return protobuf::LogLevel::DEBUG;
    }
}