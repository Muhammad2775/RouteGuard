#pragma once

#include <expected>

#include <IPAddressUtilities.hpp>
#include <Packet.hpp>
#include <ValidationError.hpp>

class PacketValidator
{
public:

    inline std::expected<void, ValidationError>
    Validate(const Packet& packet)
    {
        if (packet.IsMalformed)
        {
            return std::unexpected
            (
                ValidationError
                {
                    ValidationErrorCode::MalformedPacket, "Packet marked as malformed"
                }
            );
        }

        if (!IPAddressUtilities::IsValidIPAddress(packet.SourceIP))
        {
            return std::unexpected
            (
                ValidationError
                {
                    ValidationErrorCode::InvalidSourceIP,
                    "Invalid source IP address"
                }
            );
        }

        if (!IPAddressUtilities::IsValidIPAddress(packet.DestinationIP))
        {
            return std::unexpected
            (
                ValidationError
                {
                    ValidationErrorCode::InvalidDestinationIP,
                    "Invalid destination IP address"
                }
            );
        }

        if (packet.TTL <= 0)
        {
            return std::unexpected
            (
                ValidationError
                {
                    ValidationErrorCode::InvalidTTL,
                    "Packet TTL expired"
                }
            );
        }

        return {};
    }
};