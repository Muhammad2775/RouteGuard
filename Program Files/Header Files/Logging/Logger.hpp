#pragma once

#include <iostream>
#include <string>

class Logger
{
public:

    inline void Info(const std::string& message)
    {
        std::cout << "[INFO] " << message << '\n';
    }

    inline void Warning(const std::string& message)
    {
        std::cout << "[WARNING] " << message << '\n';
    }

    inline void Alert(const std::string& message)
    {
        std::cout << "[ALERT] " << message << '\n';
    }
};