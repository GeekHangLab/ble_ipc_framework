cmake_minimum_required(VERSION 3.20)

project(BLE_IPC_Framework)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include third party directories
include_directories(
    third_party/spdlog/include
    third_party/nlohmann_json/include
    src
    src/Utils
)

file(GLOB SOURCES
    src/*.cpp
    src/Utils/*.cpp
)

add_executable(ble_ipc_framework ${SOURCES})
