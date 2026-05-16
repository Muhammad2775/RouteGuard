#pragma once

#include <string_view>

namespace RouteGuard
{
    namespace Constants 
    {
        constexpr const std::string_view APPLICATION_NAME = "RouteGuard";
        constexpr const std::string_view APPLICATION_VERSION = "1.0";

        constexpr int DEFAULT_TTL = 64;
        constexpr int ALERT_THRESHOLD = 5;
    }
}