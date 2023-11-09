#include "utils.h"

#include <codecvt>
#include <locale>


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