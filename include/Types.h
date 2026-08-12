#pragma once

#include<cstdint>
#include <ctime>

enum class Side {
    BUY,
    SELL
};

using Price = std::int32_t;
using Quantity = std::uint32_t;
using OrderId = std::uint64_t;
using Time_t = std::time_t;