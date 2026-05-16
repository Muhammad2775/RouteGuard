#pragma once

#include <string>

enum class ProtocolType
{
    TCP,
    UDP,
    ICMP,
    UNKNOWN
};

struct Packet
{
    std::string SourceIP;
    std::string DestinationIP;

    ProtocolType Protocol = ProtocolType::UNKNOWN;

    int TTL = 64;
    int Port = 0;
    int PayloadSize = 0;

    bool IsMalformed = false;
};