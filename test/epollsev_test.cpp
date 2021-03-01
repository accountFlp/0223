#include "epollsev.h"
#include "log.h"
#include <string>
#include "yaml-cpp/yaml.h"
#include <signal.h>
void handle_signal(int sig){
    std::cout<<"signal handle:"<<sig<<std::endl;
    if(sig==SIGABRT){
        M_LOG::mbacktrace();
    }
    if(sig==SIGTERM || sig==SIGKILL){
        M_LOG::mbacktrace();
    }
    exit(0);
}
int main(){
    spdlog::enable_backtrace(10);
    signal(SIGINT,handle_signal);
    signal(SIGABRT,handle_signal);
    signal(SIGKILL,handle_signal);
    signal(SIGPIPE,handle_signal);
    signal(SIGTERM,handle_signal);
    signal(SIGSEGV,handle_signal);
    YAML::Node config = YAML::LoadFile("config.yaml");
    spdlog::logger m_logger=M_LOG::multi_sink_example(config["logfilePath"].as<std::string>().c_str(),\
                                            M_LOG::getLogLevel(config["consoleLevel"].as<std::string>()),\
                                            M_LOG::getLogLevel(config["logfileLevel"].as<std::string>()),\
                                            M_LOG::getLogLevel(config["loggerLevel"].as<std::string>()));
    EPOLL::EPOLLSEV sev(m_logger,std::string("127.0.0.1"),8080,10);
    m_logger.debug("-------------");
    MDEBUG(&m_logger,"haha {}",123);
    MINFO(&m_logger,"MINFO {}",123);
    MWARN(&m_logger,"MWARN {}",123);
    MERROR(&m_logger,"MWARN {}",123);
    sev.init();
    sev.start();
    return 0;
}