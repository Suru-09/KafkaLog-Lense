#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>
#include <chrono>

#include "LogMessage.pb.h"
namespace utils {

std::wstring to_wstring(const std::string& stringToConvert);
std::string wstring_to_utf8 (const std::wstring& stringToConvert);

protobuf::LogMessage createLogMessage(const std::string& uid, const std::string& message, 
    const protobuf::LogLevel& logLevel, const protobuf::ApplicationLanguage& applicationLanguage,
    const std::chrono::system_clock::time_point& currentTime = std::chrono::system_clock::now()
);

}   // namespace utils

#endif  // _UTILS_H_