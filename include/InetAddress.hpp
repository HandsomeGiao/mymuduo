#pragma once

#include <string>

#include "netinet/in.h"
#include "noncopyable.hpp"

namespace mymuduo {
// just for ipv4
class InetAddress : noncopyable {
 public:
  explicit InetAddress(std::string ip, uint16_t port);
  explicit InetAddress(sockaddr_in &addr);

  std::string toIp() const;
  uint16_t toPort() const;
  std::string toIpPort() const;
  const sockaddr *getSockAddr() const { return (const sockaddr *)&addr_; }

 private:
  sockaddr_in addr_;
};
}  // namespace mymuduo