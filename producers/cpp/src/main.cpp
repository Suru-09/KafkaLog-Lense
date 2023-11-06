#include <iostream>
#include <fstream>

#include <nlohmann/json.hpp>
#include <openssl/sha.h>
#include <librdkafka/rdkafkacpp.h>

using json = nlohmann::json;

int main(int argc, char *argv[]) {
    std::cout << "Hello World!" << std::endl;
    return 0;
}