#include "../include/InetAddress.hpp"

#include <strings.h>
#include <cstdio>
#include <cstring>
#include <arpa/inet.h>

mymuduo::InetAddress::InetAddress(std::string ip, uint16_t port)
{
    bzero(&addr_, sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port);
    addr_.sin_addr.s_addr = inet_addr(ip.c_str());
}
mymuduo::InetAddress::InetAddress(sockaddr_in &addr)
    : addr_(addr)
{
}
std::string mymuduo::InetAddress::toIp() const
{
    char buf[64] = {0};
    inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof(buf));
    return std::string(buf);
}
uint16_t mymuduo::InetAddress::toPort() const
{
    return ntohs(addr_.sin_port);
}

std::string mymuduo::InetAddress::toIpPort() const
{
    char buf[64] = {0};
    inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof(buf));
    int end = strlen(buf);
    uint16_t port = ntohs(addr_.sin_port);
    snprintf(buf + end, sizeof(buf) - end, ":%u", port);
    return std::string(buf);
}
