#include "Order.h"
#include <iostream>

using namespace std;

Order::Order(
    int orderId,
    int foodId,
    string foodName,
    int quantity,
    double totalPrice
) {
    this->orderId = orderId;
    this->foodId = foodId;
    this->foodName = foodName;
    this->quantity = quantity;
    this->totalPrice = totalPrice;
}

int Order::getOrderId() const {
    return orderId;
}

int Order::getFoodId() const {
    return foodId;
}

string Order::getFoodName() const {
    return foodName;
}

int Order::getQuantity() const {
    return quantity;
}

double Order::getTotalPrice() const {
    return totalPrice;
}

void Order::display() const {
    cout << "Order ID: " << orderId
         << " | Food: " << foodName
         << " | Quantity: " << quantity
         << " | Total: $" << totalPrice
         << endl;
}