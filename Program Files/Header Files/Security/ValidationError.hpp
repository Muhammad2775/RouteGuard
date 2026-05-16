#pragma once

#include <string>

enum class ValidationErrorCode
{
    InvalidSourceIP,
    InvalidDestinationIP,
    InvalidTTL,
    MalformedPacket
};

struct ValidationError
{
    ValidationErrorCode Code;

    std::string Message;
};