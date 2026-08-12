#pragma once

#include "Types.h"
#include "Order.h"

#include <deque>

class PriceLevel {
    public:
        void add(OrderId orderId);
        void remove(OrderId orderId);
        
    private:
        Price price_;
        std::deque<OrderId> orderIds_;

};