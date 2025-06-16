#include "ProtocolParser.h"
#include "Utils/Logger.h"

// 简化版协议解析（模拟）
// 后续你可以在这里实现完整协议帧解析逻辑

ProtocolParser::ProtocolParser() {
    spdlog::info("ProtocolParser initialized.");
}

ProtocolParser::~ProtocolParser() {
    spdlog::info("ProtocolParser destroyed.");
}

nlohmann::json ProtocolParser::parsePacket(const std::vector<uint8_t>& raw_data) {
    spdlog::info("Parsing BLE packet...");

    // 模拟协议解析
    // 后续你按你真实的协议格式拆解 raw_data

    nlohmann::json result;

    if (raw_data.size() >= 4) {
        uint8_t cmd = raw_data[0];
        uint16_t voltage_raw = (raw_data[1] << 8) | raw_data[2];
        uint8_t temp_raw = raw_data[3];

        float voltage = voltage_raw / 1000.0f;
        float temperature = temp_raw;

        result["cmd"] = cmd;
        result["voltage"] = voltage;
        result["temperature"] = temperature;
    } else {
        result["error"] = "invalid packet length";
    }

    return result;
}
