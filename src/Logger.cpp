#include "../include/Logger.hpp"

#include <iostream>

namespace mymuduo
{
#define LOG_INFO(logmsgFormat, ...)                       \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::getInstance();           \
        logger.sertLogLevel(INFO);                        \
        char buf[1024];                                   \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)

#define LOG_ERROR(logmsgFormat, ...)                      \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::getInstance();           \
        logger.sertLogLevel(ERROR);                       \
        char buf[1024];                                   \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)

#define LOG_FATAL(logmsgFormat, ...)                      \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::getInstance();           \
        logger.sertLogLevel(FATAL);                       \
        char buf[1024];                                   \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)

#ifdef MYMUDUO_DEBUG
#define LOG_DEBUG(logmsgFormat, ...)                      \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::getInstance();           \
        logger.sertLogLevel(DEBUG);                       \
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
        logger.sertLogLevel(WARN);                        \
        char buf[1024];                                   \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)

    void Logger::setLogLevel(LogLevel level)
    {
        level_ = level;
    }

    Logger &Logger::getInstance()
    {
        static Logger logger;
        return logger;
    }

    void Logger::log(const std::string &msg)
    {
        switch (level_)
        {
        case INFO:
            std::cout << "INFO: " << msg << std::endl;
            break;
        case ERROR:
            std::cerr << "ERROR: " << msg << std::endl;
            break;
        case FATAL:
            std::cerr << "FATAL: " << msg << std::endl;
            break;
        case DEBUG:
            std::cout << "DEBUG: " << msg << std::endl;
            break;
        case WARN:
            std::cout << "WARN: " << msg << std::endl;
            break;
        default:
            break;
        }

        std::cout << "[now time]" << msg << std::endl;
    }

} // namespace mymuduo
