#ifndef FOOD_LINKED_LIST_H
#define FOOD_LINKED_LIST_H

#include "Food.h"
#include <string>

class FoodHashTable;

class FoodLinkedList
{
private:

    struct Node
    {
        Food food;
        Node *next;

        Node(Food food)
            : food(food), next(nullptr)
        {
        }
    };

    Node *head;

public:

    FoodLinkedList();

    bool addFood(Food food);

    Food *searchFood(int id);

    Food *getFoodPointer(int id);

    bool deleteFood(int id);

    bool removeFood(
        int id,
        Food &deletedFood);

    bool reduceQuantity(
        int id,
        int quantity);

    int countFoods() const;

    void displayFoods() const;

    bool loadFromFile(
        const std::string &filename);

    bool saveToFile(
        const std::string &filename) const;

    void buildHashTable(
        FoodHashTable &foodTable);

    // SORTING FUNCTIONS
    void sortByID();
    void sortByName();
    void sortByPrice();
    void sortByQuantity();

    ~FoodLinkedList();
};

#endif