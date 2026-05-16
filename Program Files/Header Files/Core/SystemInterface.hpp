#pragma once

#include <iostream>

class SystemInterface
{
public:

    inline void Initialize()
    {
        std::cout << "[RouteGuard] System Initialized\n";
    }

    inline void Run()
    {
        std::cout << "[RouteGuard] Simulation Running\n";
    }

    inline void Shutdown()
    {
        std::cout << "[RouteGuard] System Shutdown\n";
    }
};