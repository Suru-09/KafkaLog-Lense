#include "utils.h"

#include <codecvt>
#include <locale>

#include "LogMessage.pb.h"

#include <google/protobuf/util/time_util.h>

std::wstring utils::to_wstring(const std::string& stringToConvert)
{
    std::wstring wideString = 
        std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(stringToConvert);
    return wideString;
}

std::string utils::wstring_to_utf8 (const std::wstring& stringToConvert)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.to_bytes(stringToConvert);
}

protobuf::LogMessage utils::createLogMessage(const std::string& uid, const std::string& message, 
    const protobuf::LogLevel& logLevel, const protobuf::ApplicationLanguage& applicationLanguage,
    const std::chrono::system_clock::time_point& currentTime/*= std::chrono::system_clock::now()*/)
{
    protobuf::LogMessage logMessage;
    logMessage.set_uid(uid);
    logMessage.set_message(message);
    logMessage.set_log_level(logLevel);
    logMessage.set_app_lang(applicationLanguage);

    google::protobuf::Timestamp* timestamp = new google::protobuf::Timestamp;
    timestamp->set_seconds(std::chrono::time_point_cast<std::chrono::seconds>(currentTime).time_since_epoch().count());
    timestamp->set_nanos(0);
    logMessage.set_allocated_timestamp(timestamp);
    
    return logMessage;
}