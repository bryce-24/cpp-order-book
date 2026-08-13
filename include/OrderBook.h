#pragma once

#include "Order.h"
#include "PriceLevel.h"
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <functional>

class OrderBook {
public:
    void addOrder(const Order& order);
    void cancelOrder();
    void printBook() const;

private:
    std::map<Price, std::deque<OrderId>, std::greater<Price>> bids_;
    std::map<Price, std::deque<OrderId>, std::greater<Price>> asks_;

    std::unordered_map<OrderId, Order> orders_;
};
