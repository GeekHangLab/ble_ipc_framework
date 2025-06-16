#include "Logger.h"
#include <filesystem>  // ✅ 用于自动创建logs目录

void Logger::init() {
    try {
        std::filesystem::create_directories("logs");
        auto file_logger = spdlog::basic_logger_mt("file_logger", "logs/logfile.txt");
        auto console_logger = spdlog::stdout_color_mt("console");

        spdlog::set_default_logger(file_logger);
        spdlog::set_level(spdlog::level::info);
        spdlog::flush_on(spdlog::level::info);

        spdlog::info("Logger initialized.");
        console_logger->info("Logger initialized.");
    } catch (const spdlog::spdlog_ex& ex) {
        printf("Log initialization failed: %s\n", ex.what());
    }
}
