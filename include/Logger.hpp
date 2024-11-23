#pragma once

#include "noncopyable.hpp"

#include <string>

namespace mymuduo
{
    enum LogLevel
    {
        INFO,
        ERROR,
        FATAL,
        DEBUG,
        WARN,
    };

    class Logger : noncopyable
    {
    public:
        static Logger &getInstance();

        void setLogLevel(LogLevel level);
        void log(const std::string &msg);

    private:
        int level_;
    };

}; // namespace mymuduo
