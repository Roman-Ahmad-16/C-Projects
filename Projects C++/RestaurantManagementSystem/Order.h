#ifndef ORDER_H
#define ORDER_H

#include <string>

using namespace std;

class Order {
private:
    int orderId;
    int foodId;
    string foodName;
    int quantity;
    double totalPrice;

public:
    Order(
        int orderId,
        int foodId,
        string foodName,
        int quantity,
        double totalPrice
    );

    int getOrderId() const;
    int getFoodId() const;
    string getFoodName() const;
    int getQuantity() const;
    double getTotalPrice() const;

    void display() const;
};

#endif