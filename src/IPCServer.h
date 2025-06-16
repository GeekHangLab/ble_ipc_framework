#pragma once

#include "BLEManager.h"
#include "ProtocolParser.h"
#include <thread>
#include <atomic>
#include <vector>
#include <mutex>

class IPCServer {
public:
    IPCServer(BLEManager& ble, ProtocolParser& parser);
    ~IPCServer();

    void start(uint16_t port);

private:
    void serverThread(uint16_t port);
    void handleClient(int client_socket);

    BLEManager& bleManager;
    ProtocolParser& protocolParser;

    std::atomic<bool> running;
    std::thread serverThreadHandle;
};
