#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"
#include "log.h"
#include "poll_server.h"
#define  configPath=""



int main(int, char**) {
    YAML::Node config = YAML::LoadFile("config.yaml");
    spdlog::logger m_logger=M_LOG::multi_sink_example(config["logfilePath"].as<std::string>().c_str(),\
                                            M_LOG::getLogLevel(config["consoleLevel"].as<std::string>()),\
                                            M_LOG::getLogLevel(config["logfileLevel"].as<std::string>()),\
                                            M_LOG::getLogLevel(config["loggerLevel"].as<std::string>()));
    m_logger.debug("curpath:{}",config["curpath"].as<std::string>());
    m_logger.debug("logfilePath:{}",config["logfilePath"].as<std::string>());
    m_logger.debug("logfileLevel:{}",config["logfileLevel"].as<std::string>());
    m_logger.debug("curpath:{}",config["loggerLevel"].as<std::string>());
    m_logger.debug("curpath:{}",config["curpath"].as<std::string>());


    F_poll::pollSev m_server(m_logger,"127.0.0.1",8888);
    m_server.init();
    m_server.start();

//     std::cout << "curpath:" << config["curpath"].as<std::string>() <<std::endl;
//     std::cout << "intertime:" << config["intertime"].as<int>() << std::endl;
//     config["intertime"]=99;
// //change config
//     std::ofstream fout("config.yaml");
//     fout<<config;
//     fout.close(); 

    std::cout << "intertime:" << config["intertime"].as<int>() << std::endl;
    std::cout << "Hello, world!\n";
}
