#pragma once

#include <cstdint>
#include <string>

namespace mymuduo {
class TimeStamp {
 public:
  explicit TimeStamp();
  explicit TimeStamp(int64_t);
  static TimeStamp now();
  std::string toString() const;

 private:
  int64_t microSecondsSinceEpoch_;
};
};  // namespace mymuduo