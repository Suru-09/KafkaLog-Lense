#ifndef _NORMAL_DISTRIBUTION_H_
#define _NORMAL_DISTRIBUTION_H_

#include <iostream>
#include <random>
#include <string>

#include "LogMessage.pb.h"

class NormalDistribution {

public:
    NormalDistribution(double mean, double stddev);
    ~NormalDistribution() = default;
    
    protobuf::LogLevel getLogLevelSample();

private:
    std::default_random_engine m_generator;
    std::normal_distribution<double> m_distribution;
};

#endif // _NORMAL_DISTRIBUTION_H_