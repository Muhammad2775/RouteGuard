#pragma once

#include <string>
#include <vector>

#include <Packet.hpp>

struct ACLRule
{
    std::string BlockedSourceIP;
};

class AccessControlList
{
private:

    std::vector<ACLRule> Rules;

public:

    inline void AddRule(const ACLRule& rule)
    {
        Rules.emplace_back(rule);
    }

    inline bool IsAllowed(const Packet& packet) const
    {
        for (const ACLRule& rule : Rules)
        {
            if (packet.SourceIP == rule.BlockedSourceIP)
            {
                return false;
            }
        }

        return true;
    }
};