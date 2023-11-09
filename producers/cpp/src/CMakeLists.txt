cmake_minimum_required(VERSION 3.22)


add_executable(${PROJECT_NAME}
    utils.cpp
    uid.cpp
    kafka_producer.cpp
    normal_distribution.cpp
    main.cpp
)

# Finding all generated files by Protobuf
file(GLOB_RECURSE GENERATED_FILES
    ${CMAKE_SOURCE_DIR}/generated/*.cc
    ${CMAKE_SOURCE_DIR}/generated/*.cpp
)

# avoid having main.cpp's in this list.
list(FILTER GENERATED_FILES EXCLUDE REGEX "main.cpp")


add_library(${PROJECT_NAME}-generated
        ${GENERATED_FILES}
)

target_include_directories(${PROJECT_NAME}-generated
    PRIVATE
        ${CMAKE_SOURCE_DIR}/generated
)

target_link_libraries(${PROJECT_NAME}-generated
    PRIVATE
        ${PROTOBUF_LIBRARY}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        rdkafka++
        OpenSSL::SSL
        ${PROTOBUF_LIBRARY}
        ${PROJECT_NAME}-generated
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE
        ${INCL_DIR}
)

