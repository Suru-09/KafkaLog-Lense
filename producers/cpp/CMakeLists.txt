cmake_minimum_required(VERSION 3.22)

project(CPP_CONSUMER)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# change from default CLion output directory to my preferred one
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)

# Check if a C++ compiler is available
if(CMAKE_CXX_COMPILER)
    message(STATUS "[PM] C++ compiler found: ${CMAKE_CXX_COMPILER}")

    # Get C++ compiler version
    execute_process(
        COMMAND ${CMAKE_CXX_COMPILER} --version
        OUTPUT_VARIABLE compiler_version
    )
    string(REGEX MATCH "[0-9]+\\.[0-9]+\\.[0-9]+" compiler_version "${compiler_version}")
    message(STATUS "[PM] C++ compiler version: ${compiler_version}")
else()
    message(FATAL_ERROR "C++ compiler not found. Please install a C++ compiler.")
endif()

message(STATUS "=====================================")
find_package(OpenSSL REQUIRED)
message(STATUS "OpenSSL found: ${OPENSSL_FOUND}")
message(STATUS "OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")
message(STATUS "=====================================")



set(INCL_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/libs
    ${OPENSSL_INCLUDE_DIR}
)

add_subdirectory(src)