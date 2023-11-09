#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>

namespace utils {

std::wstring to_wstring(const std::string& stringToConvert);
std::string wstring_to_utf8 (const std::wstring& stringToConvert);

}   // namespace utils

#endif  // _UTILS_H_