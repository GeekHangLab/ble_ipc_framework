#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

class ProtocolParser {
public:
    ProtocolParser();
    ~ProtocolParser();

    // 解析原始BLE数据帧，返回JSON对象
    nlohmann::json parsePacket(const std::vector<uint8_t>& raw_data);
};
