#include "OrderBook.h"
#include <iostream>

void OrderBook::addOrder(const Order& order) {
    orders_.emplace(order.getOrderId(), order);
}

void OrderBook::printBook() const {
    for (const auto& [orderId, order] : orders_) {
        std::cout << order << '\n';
    }
}

void OrderBook::cancelOrder() {
    if (orders_.empty()) {
        std::cout << "There are currently no orders." << '\n';
        return;
    }

    OrderId id;
    std::cout << "Enter the ID of the order you wish to cancel: ";
    std::cin >> id;

    for (auto it = orders_.begin(); it != orders_.end(); ++it) {
        if (it->first == id) {
            orders_.erase(it);
            std::cout << "Order " << id << " was cancelled." << '\n';
            return;
        }
    }

    std::cout << "Order " << id << " was not found." << '\n';
}

