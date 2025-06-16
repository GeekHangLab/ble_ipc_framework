#include <iostream>
#include <winsock2.h>
#include <chrono>
#include <thread>

#include "BLEManager.h"
#include "IPCServer.h"
#include "ProtocolParser.h"
#include "Utils/Logger.h"

int main() {
    Logger::init();

#ifdef _WIN32
    WSADATA wsaData;
    int wsaStartupResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (wsaStartupResult != 0) {
        spdlog::error("WSAStartup failed: {}", wsaStartupResult);
        return 1;
    }
#endif

    std::cout << "BLE-IPC Framework Starting..." << std::endl;
    spdlog::info("BLE-IPC Framework initialized.");

    BLEManager bleManager;
    ProtocolParser protocolParser;
    IPCServer server(bleManager, protocolParser);
    server.start(9000);

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

#ifdef _WIN32
    WSACleanup();
#endif

    return 0;
}
