#include <iostream>

#include "uid.h"


int main(int argc, char *argv[]) {
    uid::UID uid;
    uid.initUID();
    auto uidStr = uid.getUID();
    for(const auto&  c: uidStr) {
        std::cout << std::hex << static_cast<int>(c);
    }
    std::cout << std::endl;
    return 0;
}