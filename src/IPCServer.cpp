#include "IPCServer.h"
#include "Utils/Logger.h"
#include <iostream>
#include <cstring>
#include <sys/types.h>
#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif
#include <nlohmann/json.hpp>

IPCServer::IPCServer(BLEManager& ble, ProtocolParser& parser)
    : bleManager(ble), protocolParser(parser), running(false) {
    spdlog::info("IPCServer initialized.");
}

IPCServer::~IPCServer() {
    running = false;
    if (serverThreadHandle.joinable()) {
        serverThreadHandle.join();
    }
    spdlog::info("IPCServer destroyed.");
}

void IPCServer::start(uint16_t port) {
    spdlog::info("Starting server thread...");
    running = true;
    serverThreadHandle = std::thread([this, port]() {
        this->serverThread(port);
    });
    spdlog::info("Server thread launched.");
}


void IPCServer::serverThread(uint16_t port) {
    #ifdef _WIN32
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2,2), &wsaData);
    #endif
    
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket < 0) {
            spdlog::error("Failed to create socket.");
            return;
        }
        spdlog::info("Socket created successfully.");
    
        sockaddr_in server_addr{};
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = INADDR_ANY;
    
        int bind_result = bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
        if (bind_result < 0) {
            spdlog::error("Bind failed, error code: {}", WSAGetLastError());
            return;
        }
        spdlog::info("Bind succeeded.");
    
        listen(server_socket, 5);
        spdlog::info("IPCServer listening on port {}", port);
    
        while (running) {
            sockaddr_in client_addr{};
    #ifdef _WIN32
            int addr_len = sizeof(client_addr);
    #else
            socklen_t addr_len = sizeof(client_addr);
    #endif
            int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
            if (client_socket >= 0) {
                spdlog::info("Client connected.");
                std::thread(&IPCServer::handleClient, this, client_socket).detach();
            }
        }
    
    #ifdef _WIN32
        closesocket(server_socket);
        WSACleanup();
    #else
        close(server_socket);
    #endif
    }
    

void IPCServer::handleClient(int client_socket) {
    // 模拟发送测试数据，后期用BLE数据替换
    while (running) {
        std::vector<uint8_t> mockData = {0x10, 0x10, 0x00, 0x25};
        auto json_result = protocolParser.parsePacket(mockData);

        std::string json_str = json_result.dump() + "\n";
#ifdef _WIN32
        send(client_socket, json_str.c_str(), (int)json_str.size(), 0);
#else
        send(client_socket, json_str.c_str(), json_str.size(), 0);
#endif
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

#ifdef _WIN32
    closesocket(client_socket);
#else
    close(client_socket);
#endif
}
