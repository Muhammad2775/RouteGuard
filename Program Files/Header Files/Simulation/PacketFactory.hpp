#pragma once

#include <Packet.hpp>

namespace PacketFactory
{
    inline Packet
    CreateTCPPacket(
        const std::string& sourceIP,
        const std::string& destinationIP,
        int port)
    {
        return Packet
        {
            .SourceIP = sourceIP,
            .DestinationIP = destinationIP,
            .Protocol = ProtocolType::TCP,
            .TTL = 64,
            .Port = port,
            .PayloadSize = 1024,
            .IsMalformed = false
        };
    }

    inline Packet
    CreateUDPPacket(
        const std::string& sourceIP,
        const std::string& destinationIP,
        int port)
    {
        return Packet
        {
            .SourceIP = sourceIP,
            .DestinationIP = destinationIP,
            .Protocol = ProtocolType::UDP,
            .TTL = 64,
            .Port = port,
            .PayloadSize = 512,
            .IsMalformed = false
        };
    }

    inline Packet
    CreateICMPPacket(
        const std::string& sourceIP,
        const std::string& destinationIP)
    {
        return Packet
        {
            .SourceIP = sourceIP,
            .DestinationIP = destinationIP,
            .Protocol = ProtocolType::ICMP,
            .TTL = 128,
            .Port = 0,
            .PayloadSize = 64,
            .IsMalformed = false
        };
    }

    inline Packet
    CreateMalformedPacket()
    {
        return Packet
        {
            .SourceIP = "999.999.999.999",
            .DestinationIP = "192.168.1.10",
            .Protocol = ProtocolType::UNKNOWN,
            .TTL = -1,
            .Port = -1,
            .PayloadSize = 0,
            .IsMalformed = true
        };
    }
}