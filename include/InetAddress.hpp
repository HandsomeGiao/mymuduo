#pragma once

#include "noncopyable.hpp"
#include "netinet/in.h"

#include <string>

namespace mymuduo
{
    // just for ipv4
    class InetAddress : noncopyable
    {
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
}