#pragma once

#include "Types.h"
#include "Order.h"

#include <deque>

class PriceLevel {
    public:
        explicit PriceLevel(Price price);
        void add(OrderId orderId);
        void remove(OrderId orderId);
        Price getPrice() const;
        const std::deque<OrderId>& getOrderIds() const;
        
    private:
        Price price_;
        std::deque<OrderId> orderIds_;

};