#pragma once

#include <string>

struct Packet
{
    std::string SourceIP;
    std::string DestinationIP;
    std::string Protocol;

    int TTL = 64;
    int Port = 0;
    int PayloadSize = 0;
};