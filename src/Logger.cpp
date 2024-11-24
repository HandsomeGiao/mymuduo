#include "../include/Logger.hpp"

#include <iostream>

#include "../include/TimeStamp.hpp"

namespace mymuduo {
void Logger::setLogLevel(LogLevel level) { level_ = level; }

Logger &Logger::getInstance() {
  static Logger logger;
  return logger;
}

void Logger::log(const std::string &msg) {
  switch (level_) {
    case INFO:
      std::cout << "[INFO] ";
      break;
    case ERROR:
      std::cout << "[ERROR]";
      break;
    case FATAL:
      std::cout << "[FATAL]";
      break;
    case DEBUG:
      std::cout << "[DEBUG]";
      break;
    case WARN:
      std::cout << "[WARN] ";
      break;
    default:
      break;
  }

  std::cout << "[" << TimeStamp::now().toString() << "]" << msg << std::endl;
}

}  // namespace mymuduo
