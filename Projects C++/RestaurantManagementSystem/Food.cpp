#include "Food.h"
#include <iostream>

using namespace std;

Food::Food() {
    id = 0;
    name = "";
    quantity = 0;
    price = 0.0;
}

Food::Food(int id, string name, int quantity, double price) {
    this->id = id;
    this->name = name;
    this->quantity = quantity;
    this->price = price;
}

int Food::getId() const {
    return id;
}

string Food::getName() const {
    return name;
}

int Food::getQuantity() const {
    return quantity;
}

double Food::getPrice() const {
    return price;
}

void Food::setName(string name) {
    this->name = name;
}

void Food::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Food::setPrice(double price) {
    this->price = price;
}

void Food::display() const {
    cout << "ID: " << id
         << " | Name: " << name
         << " | Quantity: " << quantity
         << " | Price: $" << price << endl;
}