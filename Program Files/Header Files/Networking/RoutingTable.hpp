#pragma once

#include <string>
#include <vector>

struct RouteEntry
{
    std::string DestinationNetwork;
    std::string NextHop;
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

    inline const std::vector<RouteEntry>& GetRoutes() const
    {
        return Routes;
    }
};