#pragma once

#include <string>
#include <optional>

#include <RoutingTable.hpp>

class RoutingEngine
{
public:

    inline std::optional<RouteEntry> ResolveRoute(const RoutingTable& routingTable, const std::string& destinationIP)
    {
        for (const RouteEntry& route : routingTable.GetRoutes())
        {
            if (destinationIP.starts_with(route.DestinationNetwork))
            {
                return route;
            }
        }

        return std::nullopt;
    }
};