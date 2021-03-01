#include "log.h"
#include <iostream>
#include <cxxabi.h>
#include <execinfo.h>
namespace M_LOG{
    static std::string demangle(const char* symbol);
    void mbacktrace()
    {
        void *array[100];
        size_t size;
        char **strings;
        int i;
        size = backtrace (array, 100);
        strings = backtrace_symbols (array, size);
        if (NULL == strings)
        {
            printf("backtrace_symbols\n");
            return ;
        } 
        for (i = 0; i < (int)size; i++)
        {
            std::cout<<demangle(strings[i])<<std::endl;
        }
        free(strings);
    }
    std::string demangle(const char* symbol)
    {
        size_t size;
        int status;
        char temp[128];
        char* demangled;
        //first, try to demangle a c++ name
        if (1 == sscanf(symbol, "%*[^(]%*[^_]%127[^)+]", temp)) {
            if (NULL != (demangled = abi::__cxa_demangle(temp, NULL, &size, &status))) {
                std::string result(demangled);
                free(demangled);
                return result;
            }
        }
        //if that didn't work, try to get a regular c symbol
        if (1 == sscanf(symbol, "%127s", temp)) {
            return temp;
        }
        //if all else fails, just return the symbol
        return symbol;
    }

    spdlog::level::level_enum getLogLevel(std::string l){
        spdlog::level::level_enum m_level;
        if(l==std::string("trace")){
            m_level=spdlog::level::trace;
        }else if(l==std::string("debug")){
            m_level=spdlog::level::debug;
        }else if(l==std::string("info")){
            m_level=spdlog::level::info;
        }else if(l==std::string("warn")){
            m_level=spdlog::level::warn;
        }else if(l==std::string("err")){
            m_level=spdlog::level::err;
        }else if(l==std::string("critical")){
            m_level=spdlog::level::critical;
        }else if(l==std::string("off")){
            m_level=spdlog::level::off;
        }else{
            m_level=spdlog::level::n_levels;
        }
        return m_level;
    }
    spdlog::logger multi_sink_example(const char *logfile,spdlog::level::level_enum console_level,spdlog::level::level_enum file_level,spdlog::level::level_enum logger_level)
    {
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_level(console_level);
        console_sink->set_pattern("[multi_sink] [%^%l%$] %v");

        // auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logfile", true);
        // file_sink->set_level(file_level);
        
        // auto rotate_file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(logfile,1024*1024 * 5, 3, true);
        // rotate_file_sink->set_level(file_level);
        auto daily_file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(logfile,0,0,false,1);
        daily_file_sink->set_level(file_level);

        spdlog::logger logger("multi_sink", {console_sink,daily_file_sink});
        logger.set_level(logger_level);
        logger.set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] [%^%l%$] [thread %t] <%s>|<%#>|<%!> %v");
        logger.warn("this should appear in both console and file");
        logger.info("this message should not appear in the console, only in the file");
        return logger;
    }
}
