#pragma once

#include <print>
#include <string>

#include <Packet.hpp>

class PacketForwarder
{
public:

    inline void ForwardPacket(const Packet& packet, const std::string& nextHop)
    {
        std::println("Forwarding packet to {} via next hop {}", packet.DestinationIP, nextHop);
    }
};