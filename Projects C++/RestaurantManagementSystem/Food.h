#ifndef FOOD_H
#define FOOD_H

#include <string>

using namespace std;

class Food {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    Food();
    Food(int id, string name, int quantity, double price);

    int getId() const;
    string getName() const;
    int getQuantity() const;
    double getPrice() const;

    void setName(string name);
    void setQuantity(int quantity);
    void setPrice(double price);

    void display() const;
};

#endif