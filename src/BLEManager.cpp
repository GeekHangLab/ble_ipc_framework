#include "BLEManager.h"
#include "Utils/Logger.h"

BLEManager::BLEManager() {
    spdlog::info("BLEManager initialized.");
}

BLEManager::~BLEManager() {
    spdlog::info("BLEManager destroyed.");
}

void BLEManager::startScan() {
    spdlog::info("Starting BLE scan... (stub)");
    // TODO: WinRT BLE扫描逻辑
}

void BLEManager::stopScan() {
    spdlog::info("Stopping BLE scan... (stub)");
    // TODO: WinRT BLE停止扫描逻辑
}

void BLEManager::connectDevice(const std::string& address) {
    spdlog::info("Connecting to device: {}", address);
    // TODO: WinRT BLE连接逻辑

    // 临时模拟加入activeConnections（后期替换为真实连接）
    BLEConnection conn;
    conn.address = address;
    activeConnections[address] = conn;
}

void BLEManager::disconnectDevice(const std::string& address) {
    spdlog::info("Disconnecting from device: {}", address);
    // TODO: WinRT BLE断开逻辑
    activeConnections.erase(address);
}

void BLEManager::writeCharacteristic(const std::string& uuid, const std::vector<uint8_t>& data) {
    spdlog::info("Writing to characteristic UUID: {}", uuid);
    // TODO: BLE写特征值逻辑
}

void BLEManager::readCharacteristic(const std::string& uuid, std::vector<uint8_t>& data_out) {
    spdlog::info("Reading from characteristic UUID: {}", uuid);
    // TODO: BLE读特征值逻辑
}

void BLEManager::registerDataCallback(std::function<void(const std::string& device_id, const std::vector<uint8_t>& data)> cb) {
    spdlog::info("Data callback registered.");
    dataCallback = cb;
}
