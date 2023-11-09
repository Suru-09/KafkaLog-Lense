#include <iostream>

#include "uid.h"


int main(int argc, char *argv[]) {
    uid::UID uid;
    uid.initUID();
    auto uidStr = uid.getUID();
    std::cout << uidStr << std::endl;
    return 0;
}