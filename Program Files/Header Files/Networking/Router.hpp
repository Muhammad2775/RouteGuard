#pragma once

#include <string>

#include <AccessControlList.hpp>
#include <AlertSystem.hpp>
#include <Logger.hpp>
#include <Packet.hpp>
#include <PacketForwarder.hpp>
#include <PacketValidator.hpp>
#include <RoutingEngine.hpp>
#include <RoutingTable.hpp>
#include <ThreatDetector.hpp>
#include <ValidationError.hpp>

class Router
{
private:

    std::string Name;

    Logger RouterLogger;

    RoutingTable RouterRoutingTable;
    RoutingEngine RouterRoutingEngine;

    PacketForwarder Forwarder;
    PacketValidator Validator;

    AccessControlList ACL;

    ThreatDetector Detector;
    AlertSystem Alerts;

public:

    Router(const std::string& routerName)
        : Name(routerName)
    {
    }

    inline RoutingTable& GetRoutingTable()
    {
        return RouterRoutingTable;
    }

    inline AccessControlList& GetACL()
    {
        return ACL;
    }

    inline void ReceivePacket(Packet& packet)
    {
        RouterLogger.Info("Router " + Name + " received packet");

        const auto validation = Validator.Validate(packet);

        if (!validation.has_value())
        {
            RouterLogger.Error(validation.error().Message);
            return;
        }

        if (!ACL.IsAllowed(packet))
        {
            RouterLogger.Warning( "Packet denied by ACL");

            Detector.RegisterDeniedPacket();

            if (Detector.GetSuspiciousAttempts() >= 3)
            {
                Alerts.RaiseAlert("Repeated denied packet activity detected");
            }

            return;
        }

        --packet.TTL;

        if (packet.TTL <= 0)
        {
            RouterLogger.Warning("Packet TTL expired");
            return;
        }

        auto resolvedRoute = RouterRoutingEngine.ResolveRoute(RouterRoutingTable, packet.DestinationIP);

        if (!resolvedRoute.has_value())
        {
            RouterLogger.Warning("No route found for destination");
            return;
        }

        Forwarder.ForwardPacket(packet, resolvedRoute->NextHop);

        RouterLogger.Info("Packet forwarded successfully");
    }
};