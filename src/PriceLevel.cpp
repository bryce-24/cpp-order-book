#include "PriceLevel.h"

#include <algorithm>

PriceLevel::PriceLevel(Price price)
	: price_{price}
{}

void PriceLevel::add(OrderId orderId) {
	orderIds_.push_back(orderId);
}

void PriceLevel::remove(OrderId orderId) {
	auto it = std::find(orderIds_.begin(), orderIds_.end(), orderId);
	if (it != orderIds_.end()) {
		orderIds_.erase(it);
	}
}

Price PriceLevel::getPrice() const { return price_; }

const std::deque<OrderId>& PriceLevel::getOrderIds() const { return orderIds_; }