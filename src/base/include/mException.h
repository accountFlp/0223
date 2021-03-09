/**
 * @brief 
 * 
 */
#pragma once
#include <exception>
#include <string>
namespace BASE
{
    std::string stackTrace(bool demangle);
    class mexception:std::exception
    {
        public:
            mexception(std::string msg);
            std::string what();
            std::string mstackTrace();
        private:
            std::string msg_;
            std::string stack_;
    };
} // namespace BASE
