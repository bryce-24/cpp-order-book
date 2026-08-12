#include "Order.h"

#include <iostream>
#include <ctime>

Order::Order(OrderId orderId, Side side, Price price, Quantity quantity, Time_t timestamp)
    : orderId_{ orderId }
    , side_{ side }
    , price_{ price }
    , quantity_{ quantity }
    , initialQuantity_{ quantity }
    , remainingQuantity_{ quantity }
    , timestamp_{ timestamp }
{
}

OrderId Order::getOrderId() const { return orderId_; }
Side Order::getSide() const { return side_; }
Price Order::getPrice() const { return price_; }
Quantity Order::getQuantity() const { return quantity_; }
Quantity Order::getRemainingQuantity() const { return remainingQuantity_; }
Time_t Order::getTimestamp() const { return timestamp_; }

std::ostream& operator<<(std::ostream& os, const Order& order) {
    os << "Order ID: " << order.getOrderId() << '\n';
    os << "Side: "
       << (order.getSide() == Side::BUY ? "BUY" : "SELL")
       << '\n';
    os << "Price: " << order.getPrice() << '\n';
    os << "Quantity: " << order.getQuantity() << '\n';
    Time_t timestamp = order.getTimestamp();
    os << "Time: " << std::ctime(&timestamp);

    return os;
}
