#include "../include/TimeStamp.hpp"

#include <ctime>
#include <sstream>
#include <iomanip>

mymuduo::TimeStamp::TimeStamp()
{
}

mymuduo::TimeStamp::TimeStamp(int64_t t)
    : microSecondsSinceEpoch_(t)
{
}

mymuduo::TimeStamp mymuduo::TimeStamp::now()
{
    return TimeStamp(time(nullptr));
}

std::string mymuduo::TimeStamp::toString() const
{ 
    std::time_t time = static_cast<std::time_t>(microSecondsSinceEpoch_);
    std::tm *localTime = std::localtime(&time);

    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
