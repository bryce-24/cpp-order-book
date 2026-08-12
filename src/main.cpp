#include "OrderBook.h"
#include "Order.h"

#include <iostream>
#include <ctime>

void CreateOrder(OrderBook& book, OrderId& id) {
    int sideChoice;
    Price price;
    Quantity quantity;

    std::cout << "What is your side?\n0. Buy\n1. Sell\n";
    std::cin >> sideChoice;

    Side side = (sideChoice == 0) ? Side::BUY : Side::SELL;

    std::cout << "What is your price?\n";
    std::cin >> price;
    std::cout << "What is the quantity?\n";
    std::cin >> quantity;

    Order order(
        id,
        side,
        price,
        quantity,
        std::time(nullptr)
    );

    book.addOrder(order);
    ++id;
}

int main() {
    OrderBook book;
    OrderId id = 0;
    int choice = 0;

    while (choice != 4) {
        std::cout << "What would you like to do?\n";
        std::cout << "1. Create order\n";
        std::cout << "2. Cancel order\n";
        std::cout << "3. View created orders\n";
        std::cout << "4. Exit program\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                CreateOrder(book, id);
                break;
            case 2:
                book.cancelOrder();
                break;
            case 3:
                book.printBook();
                break;
            case 4:
                break;
            default:
                std::cout << "Invalid choice. Please choose 1-4." << '\n';
                break;
        }
    }

    return 0;
}
