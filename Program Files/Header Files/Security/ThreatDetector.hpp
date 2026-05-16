#pragma once

#include <print>

class ThreatDetector
{
private:

    int SuspiciousAttempts = 0;

public:

    inline void RegisterDeniedPacket()
    {
        ++SuspiciousAttempts;

        if (SuspiciousAttempts >= 3)
        {
            std::println("ALERT: Multiple suspicious packets detected! Potential attack in progress. Attempts {}", SuspiciousAttempts);
        }
    }

    inline int GetSuspiciousAttempts() const
    {
        return SuspiciousAttempts;
    }
};