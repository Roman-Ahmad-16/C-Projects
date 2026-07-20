#ifndef FOOD_HASH_TABLE_H
#define FOOD_HASH_TABLE_H

#include "Food.h"

class FoodHashTable
{
private:

    static const int TABLE_SIZE = 10;

    struct Node
    {
        Food* food;

        Node* next;

        Node(Food* food)
        {
            this->food =
                food;

            this->next =
                nullptr;
        }
    };

    Node* table[TABLE_SIZE];

    int hashFunction(int id) const;

public:

    FoodHashTable();

    void insert(Food* food);

    Food* search(int id);

    bool remove(int id);

    void display() const;

    ~FoodHashTable();
};

#endif