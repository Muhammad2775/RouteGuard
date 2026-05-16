#pragma once

#include <IPAddressUtilities.hpp>
#include <NetworkUtilities.hpp>

namespace Utilities
{
    inline bool
    IsInternalTraffic(
        const std::string& sourceIP,
        const std::string& destinationIP)
    {
        return
            IPAddressUtilities::IsPrivateIPAddress(sourceIP)
            &&
            IPAddressUtilities::IsPrivateIPAddress(destinationIP);
    }

    inline bool
    IsExternalTraffic(
        const std::string& sourceIP,
        const std::string& destinationIP)
    {
        return
            !IsInternalTraffic(sourceIP, destinationIP);
    }
}