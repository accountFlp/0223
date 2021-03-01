#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h" // support for loading levels from the environment variable
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
// #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
namespace M_LOG{
    #define MTRACE(lg,...) SPDLOG_LOGGER_TRACE(lg,__VA_ARGS__)
    #define MDEBUG(lg,...) SPDLOG_LOGGER_DEBUG(lg,__VA_ARGS__)
    #define MINFO(lg,...) SPDLOG_LOGGER_INFO(lg,__VA_ARGS__)
    #define MWARN(lg,...) SPDLOG_LOGGER_WARN(lg,__VA_ARGS__)
    #define MERROR(lg,...) SPDLOG_LOGGER_ERROR(lg,__VA_ARGS__)
    spdlog::logger multi_sink_example(const char *logfile,spdlog::level::level_enum console_level,spdlog::level::level_enum file_level,spdlog::level::level_enum logger_level);
    spdlog::level::level_enum getLogLevel(std::string l);
    void mbacktrace();
}