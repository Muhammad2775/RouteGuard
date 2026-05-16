#pragma once

#include <print>
#include <vector>
#include <memory>
#include <utility>

#include <Logger.hpp>
#include <PacketFactory.hpp>
#include <Router.hpp>
#include <Utilities.hpp>

class SystemInterface
{
private:

    Logger SystemLogger;

    std::vector<std::unique_ptr<Router>> Routers;

private:

    inline void ConfigureRouters()
    {
        std::unique_ptr<Router> coreRouter =  std::make_unique<Router>("CoreRouter");

        coreRouter->GetRoutingTable().AddRoute(
            {
                "192.168.",
                "255.255.0.0",
                "Gateway-A",
                "eth0"
            });

        coreRouter->GetACL().AddRule(
            {
                "10.0.0.66"
            });

        Routers.emplace_back(std::move(coreRouter));

        SystemLogger.Info("Router configuration completed");
    }

    inline void RunSimulationScenario()
    {
        SystemLogger.Info("Starting Traffic Simulation");

        Packet normalPacket =
            PacketFactory::CreateTCPPacket(
                "10.0.0.15",
                "192.168.1.25",
                443);

        Packet blockedPacket =
            PacketFactory::CreateUDPPacket(
                "10.0.0.66",
                "192.168.1.25",
                53);

        Packet malformedPacket = PacketFactory::CreateMalformedPacket();

        SystemLogger.Info("Dispatching Normal Packet");
        Routers[0]->ReceivePacket(normalPacket);

        SystemLogger.Info("Dispatching Blocked Packet");
        Routers[0]->ReceivePacket(blockedPacket);

        SystemLogger.Info("Dispatching Malformed Packet");
        Routers[0]->ReceivePacket(malformedPacket);
    }

public:

    inline void Initialize()
    {
        std::println("[SYSTEM] Initializing RouteGuard");

        ConfigureRouters();

        std::println("[SYSTEM] Initialization complete");
    }

    inline void Run()
    {
        std::println("[SYSTEM] Executing simulation runtime");

        RunSimulationScenario();

        std::println("[SYSTEM] Simulation runtime complete");
    }

    inline void Shutdown()
    {
        std::println("[SYSTEM] Shutting down RouteGuard");

        Routers.clear();

        std::println("[SYSTEM] Shutdown complete");
    }
};