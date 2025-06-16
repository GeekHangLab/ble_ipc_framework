#pragma once

#include <nlohmann/json.hpp>
#include <vector>
#include <string>

class JsonHelper {
public:
    // 示例：将二进制数据转为Hex字符串
    static std::string bytesToHexString(const std::vector<uint8_t>& data) {
        static const char* hex_chars = "0123456789ABCDEF";
        std::string hex;
        for (uint8_t byte : data) {
            hex += hex_chars[(byte >> 4) & 0x0F];
            hex += hex_chars[byte & 0x0F];
        }
        return hex;
    }

    // 示例：你可以在这里扩展通用JSON转换函数
};
