#include "../include/TimeStamp.hpp"
#include "../include/Logger.hpp"
#include "../include/InetAddress.hpp"

using namespace mymuduo;
using namespace std;

#include <iostream>

int main()
{
    InetAddress addr("192.168.1.1", 8080);
    std::cout << addr.toIp() << std::endl;
    std::cout << addr.toPort() << std::endl;
    std::cout << addr.toIpPort() << std::endl;
    return 0;
}