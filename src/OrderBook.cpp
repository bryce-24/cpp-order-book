#include "OrderBook.h"
#include <iostream>
#include <algorithm>

void OrderBook::addOrder(const Order& order) {
    auto id = order.getOrderId();
    orders_.emplace(id, order);

    // Insert into the appropriate price map
    Price price = order.getPrice();
    if (order.getSide() == Side::BUY) {
        bids_[price].push_back(id);
    } else {
        asks_[price].push_back(id);
    }
}

void OrderBook::printBook() const {

    std::cout << "ASKS:\n";
    for (const auto& [price, ids] : asks_) {
        std::cout << "Price: " << price << '\n';
        for (auto id : ids) {
            auto it = orders_.find(id);
            if (it != orders_.end()) std::cout << it->second << '\n';
        }
    }

    std::cout << "BIDS:\n";
    for (const auto& [price, ids] : bids_) {
        std::cout << "Price: " << price << '\n';
        for (auto id : ids) {
            auto it = orders_.find(id);
            if (it != orders_.end()) std::cout << it->second << '\n';
        }
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

    auto it = orders_.find(id);
    if (it == orders_.end()) {
        std::cout << "Order " << id << " was not found." << '\n';
        return;
    }

    // Remove from price level container
    const Order& order = it->second;
    Price price = order.getPrice();
    if (order.getSide() == Side::BUY) {
        auto mapIt = bids_.find(price);
        if (mapIt != bids_.end()) {
            auto &dq = mapIt->second;
            auto pos = std::find(dq.begin(), dq.end(), id);
            if (pos != dq.end()) dq.erase(pos);
            if (dq.empty()) bids_.erase(mapIt);
        }
    } else {
        auto mapIt = asks_.find(price);
        if (mapIt != asks_.end()) {
            auto &dq = mapIt->second;
            auto pos = std::find(dq.begin(), dq.end(), id);
            if (pos != dq.end()) dq.erase(pos);
            if (dq.empty()) asks_.erase(mapIt);
        }
    }

    orders_.erase(it);
    std::cout << "Order " << id << " was cancelled." << '\n';
}

