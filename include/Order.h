#pragma once

#include "Types.h"
#include <iosfwd>

class Order {
    public:
        Order(OrderId orderId, Side side, Price price, Quantity quantity, Time_t timestamp);

        OrderId getOrderId() const;
        Side getSide() const;
        Price getPrice() const;
        Quantity getQuantity() const;
        Quantity getRemainingQuantity() const;
        Time_t getTimestamp() const;
        void reduceRemaining(Quantity qty);
        

    private:
        OrderId orderId_;
        Side side_;
        Price price_;
        Quantity quantity_;
        Quantity initialQuantity_;
        Quantity remainingQuantity_;
        Time_t timestamp_;
};

std::ostream& operator<<(std::ostream& os, const Order& order);