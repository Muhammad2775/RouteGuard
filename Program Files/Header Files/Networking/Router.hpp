#pragma once

#include <iostream>
#include <string>

#include "Packet.hpp"

class Router
{
private:

    std::string Name;

public:

    Router(const std::string& routerName)
        : Name(routerName)
    {
    }

    inline void ReceivePacket(const Packet& packet)
    {
        std::cout
            << "[Router] Packet received at "
            << Name
            << " from "
            << packet.SourceIP
            << '\n';
    }
};