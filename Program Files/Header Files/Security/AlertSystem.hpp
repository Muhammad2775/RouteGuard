#pragma once

#include <print>
#include <string>

class AlertSystem
{
public:

    inline void RaiseAlert(const std::string& message)
    {
        std::println("[ALERT] {}", message);
    }
};