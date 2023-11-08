#include "uid.h"

#include <iostream>
#include <fstream>
#include <chrono>


#include <openssl/sha.h>
#include <openssl/evp.h>
#include <nlohmann/json.hpp>

namespace uid {

void UID::initUID() 
{
    if (readUIDFromFile("../uid.json")) {
        return;
    }

    std::string accumulator = "";
    std::chrono::time_point currentTime = std::chrono::system_clock::now();
    accumulator += currentTime.time_since_epoch().count();
    accumulator += generateRandomStirng(32);

    // use EVP
    unsigned char hash[SHA256_DIGEST_LENGTH];
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    EVP_DigestInit(mdctx, EVP_sha256());
    EVP_DigestUpdate(mdctx, accumulator.c_str(), accumulator.size());
    EVP_DigestFinal(mdctx, hash, NULL);
    EVP_MD_CTX_free(mdctx);
    
    m_uid = std::string(reinterpret_cast<char*>(hash));
    writeUIDToFile("../uid.json");
}

std::string UID::getUID() const
{
    return m_uid;
}

bool UID::writeUIDToFile(const std::filesystem::path& filePath) const
{
    nlohmann::json json;
    std::wstring wstr = L"";
    for (const auto& c : m_uid) {
        wstr += c;
    }
    json.emplace("uid", m_uid);

    std::ofstream file(filePath);
    if (!file.is_open()) {
        return false;
    }

    std::cout << json.dump(4) << std::endl;
    file << json.dump(4) << std::endl;

    return true;
}

bool UID::readUIDFromFile(const std::filesystem::path& filePath)
{
    nlohmann::json json;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        return false;
    }

    json = nlohmann::json::parse(file);

    if (json.contains("uid")) {
        m_uid = json["uid"];
    } 
    else 
    {
        return false;
    }

    return true;
}

std::string UID::generateRandomStirng(uint32_t strLength) const
{
    auto randChar = []() -> char
    {
        const char charset[] = "0123456789"
                               "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                               "abcdefghijklmnopqrstuvwxyz";
        const size_t maxIndex = (sizeof(charset) - 1);
        return charset[rand() % maxIndex];
    };

    std::string str(strLength, 0);
    for (uint32_t i = 0; i < strLength; i++) {
        str[i] = randChar();
    }

    return str;
}

}   // namespace uid