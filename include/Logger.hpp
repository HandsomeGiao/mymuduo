#pragma once

#include "noncopyable.hpp"

#include <string>

namespace mymuduo
{
#define LOG_INFO(logmsgFormat, ...)                       \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::getInstance();           \
        logger.setLogLevel(INFO);                         \
        char buf[1024];                                   \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)

#define LOG_ERROR(logmsgFormat, ...)                      \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::getInstance();           \
        logger.setLogLevel(ERROR);                        \
        char buf[1024];                                   \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)

#define LOG_FATAL(logmsgFormat, ...)                      \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::getInstance();           \
        logger.setLogLevel(FATAL);                        \
        char buf[1024];                                   \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)

#define MYMUDUO_DEBUG
#ifdef MYMUDUO_DEBUG
#define LOG_DEBUG(logmsgFormat, ...)                      \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::getInstance();           \
        logger.setLogLevel(DEBUG);                        \
        char buf[1024];                                   \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)
#else
#define LOG_DEBUG(logmsgFormat, ...)
#endif

#define LOG_WARN(logmsgFormat, ...)                       \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::getInstance();           \
        logger.setLogLevel(WARN);                         \
        char buf[1024];                                   \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)

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
