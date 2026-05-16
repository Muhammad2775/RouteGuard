#pragma once

#include <optional>
#include <string>
#include <vector>

struct RouteEntry
{
    std::string DestinationNetwork;
    std::string SubnetMask;
    std::string NextHop;
    std::string Interface;
};

class RoutingTable
{
private:

    std::vector<RouteEntry> Routes;

public:

    inline void AddRoute(const RouteEntry& route)
    {
        Routes.emplace_back(route);
    }

    inline std::optional<RouteEntry> FindRoute(
        const std::string& destinationNetwork) const
    {
        for (const RouteEntry& route : Routes)
        {
            if (route.DestinationNetwork == destinationNetwork)
            {
                return route;
            }
        }

        return std::nullopt;
    }

    inline const std::vector<RouteEntry>& GetRoutes() const
    {
        return Routes;
    }
};