#pragma once

#include <expected>
#include <sstream>
#include <string>
#include <vector>

enum class IPAddressError
{
    InvalidFormat,
    InvalidOctetCount,
    InvalidOctetValue
};

namespace IPAddressUtilities
{
    inline std::expected<std::vector<int>, IPAddressError>
    SplitIPAddress(const std::string& ip_address)
    {
        std::vector<int> octets;

        std::stringstream stream(ip_address);

        std::string segment;

        while (std::getline(stream, segment, '.'))
        {
            try
            {
                octets.emplace_back(std::stoi(segment));
            }
            catch (...)
            {
                return std::unexpected(
                    IPAddressError::InvalidFormat);
            }
        }

        if (octets.size() != 4)
        {
            return std::unexpected(
                IPAddressError::InvalidOctetCount);
        }

        return octets;
    }

    inline std::expected<void, IPAddressError>
    ValidateIPAddress(const std::string& ip_address)
    {
        auto splitResult = SplitIPAddress(ip_address);

        if (!splitResult.has_value())
        {
            return std::unexpected(
                splitResult.error());
        }

        for (const auto octet : splitResult.value())
        {
            if (octet < 0 || octet > 255)
            {
                return std::unexpected(IPAddressError::InvalidOctetValue);
            }
        }

        return {};
    }

    inline bool
    IsValidIPAddress(const std::string& ip_address)
    {
        return ValidateIPAddress(ip_address).has_value();
    }

    inline bool
    IsPrivateIPAddress(const std::string& ip_address)
    {
        auto splitResult = SplitIPAddress(ip_address);

        if (!splitResult.has_value())
        {
            return false;
        }

        const auto& octets = splitResult.value();

        if (octets[0] == 10)
        {
            return true;
        }

        if (octets[0] == 172 && octets[1] >= 16 && octets[1] <= 31)
        {
            return true;
        }

        if (octets[0] == 192 && octets[1] == 168)
        {
            return true;
        }

        return false;
    }
}