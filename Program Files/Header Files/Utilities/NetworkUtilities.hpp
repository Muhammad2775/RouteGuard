#pragma once

#include <string>

#include <Packet.hpp>

namespace NetworkUtilities
{
    inline std::string
    ProtocolToString(ProtocolType protocol)
    {
        switch (protocol)
        {
            case ProtocolType::TCP:
                return "TCP";

            case ProtocolType::UDP:
                return "UDP";

            case ProtocolType::ICMP:
                return "ICMP";

            default:
                return "UNKNOWN";
        }
    }

    inline bool
    IsWellKnownPort(int port)
    {
        return port >= 0 &&  port <= 1023;
    }

    inline bool
    IsRegisteredPort(int port)
    {
        return port >= 1024 && port <= 49151;
    }

    inline bool
    IsDynamicPort(int port)
    {
        return port >= 49152 &&  port <= 65535;
    }

    inline std::string
    CreatePacketSummary(
        const Packet& packet)
    {
        return
            packet.SourceIP +  " -> " + packet.DestinationIP + ProtocolToString(packet.Protocol) +
            "]";
    }
}