#pragma once

#include <string>
#include <functional>
#include <vector>
#include <unordered_map>

// 未来WinRT BLE接口在这里扩展
class BLEManager {
public:
    BLEManager();
    ~BLEManager();

    void startScan();
    void stopScan();

    void connectDevice(const std::string& address);
    void disconnectDevice(const std::string& address);

    void writeCharacteristic(const std::string& uuid, const std::vector<uint8_t>& data);
    void readCharacteristic(const std::string& uuid, std::vector<uint8_t>& data_out);

    void registerDataCallback(std::function<void(const std::string& device_id, const std::vector<uint8_t>& data)> cb);
    
private:
    // 未来扩展BLE连接管理结构
    struct BLEConnection {
        std::string address;
        // 这里预留BLE连接状态、特征值等
    };

    std::unordered_map<std::string, BLEConnection> activeConnections;

    std::function<void(const std::string& device_id, const std::vector<uint8_t>& data)> dataCallback;
};
