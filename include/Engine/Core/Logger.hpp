#pragma once

#include <memory>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/spdlog.h>
#include <variant>

template <class... Ts> struct overloads : Ts... {
    using Ts::operator()...;
};

class Logger {
  public:
    struct Stdout {};
    struct File {
        std::string filepath;
    };
    using Destination = std::variant<Stdout, File>;

    Logger(Destination coreDst = Stdout{}, Destination gameDst = Stdout{}) {
        this->core_ = coreDst.index() == 0
                          ? spdlog::stdout_logger_mt("core")
                          : spdlog::basic_logger_mt(
                                "core", std::get<File>(coreDst).filepath);

        this->game_ = gameDst.index() == 0
                          ? spdlog::stdout_logger_mt("game")
                          : spdlog::basic_logger_mt(
                                "game", std::get<File>(gameDst).filepath);
    }
    ~Logger() = default;

  private:
    std::shared_ptr<spdlog::logger> core_;
    std::shared_ptr<spdlog::logger> game_;
};

#define LOG_CORE_INFO(...) spdlog::get("core")->info(__VA_ARGS__)
#define LOG_CORE_WARN(...) spdlog::get("core")->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...) spdlog::get("core")->error(__VA_ARGS__)
#define LOG_CORE_CRITICAL(...) spdlog::get("core")->critical(__VA_ARGS__)
#define LOG_CORE_TRACE(...) spdlog::get("core")->trace(__VA_ARGS__)

#define LOG_INFO(...) spdlog::get("game")->info(__VA_ARGS__)
#define LOG_WARN(...) spdlog::get("game")->warn(__VA_ARGS__)
#define LOG_ERROR(...) spdlog::get("game")->error(__VA_ARGS__)
#define LOG_CRITICAL(...) spdlog::get("game")->critical(__VA_ARGS__)
#define LOG_TRACE(...) spdlog::get("game")->trace(__VA_ARGS__)
