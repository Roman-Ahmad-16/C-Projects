#include "FoodHashTable.h"

#include <iostream>

using namespace std;


// ======================================
// CONSTRUCTOR
// ======================================

FoodHashTable::FoodHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = nullptr;
    }
}


// ======================================
// HASH FUNCTION
// ======================================

int FoodHashTable::hashFunction(int id) const
{
    return id % TABLE_SIZE;
}


// ======================================
// INSERT FOOD POINTER
// ======================================

void FoodHashTable::insert(Food* food)
{
    if (food == nullptr)
    {
        return;
    }

    // Prevent duplicate hash-table entries
    if (search(food->getId()) != nullptr)
    {
        return;
    }

    int index =
        hashFunction(food->getId());

    Node* newNode =
        new Node(food);

    // Insert at beginning of bucket
    newNode->next =
        table[index];

    table[index] =
        newNode;
}


// ======================================
// SEARCH FOOD
// ======================================

Food* FoodHashTable::search(int id)
{
    int index =
        hashFunction(id);

    Node* current =
        table[index];

    while (current != nullptr)
    {
        if (current->food->getId() == id)
        {
            return current->food;
        }

        current =
            current->next;
    }

    return nullptr;
}


// ======================================
// REMOVE FOOD
// ======================================

bool FoodHashTable::remove(int id)
{
    int index =
        hashFunction(id);

    Node* current =
        table[index];

    Node* previous =
        nullptr;

    while (current != nullptr)
    {
        if (current->food->getId() == id)
        {
            // Removing first node
            if (previous == nullptr)
            {
                table[index] =
                    current->next;
            }
            else
            {
                previous->next =
                    current->next;
            }

            // IMPORTANT:
            // Delete only the hash node.
            // Do NOT delete current->food.
            delete current;

            return true;
        }

        previous =
            current;

        current =
            current->next;
    }

    return false;
}


// ======================================
// DISPLAY HASH TABLE
// ======================================

void FoodHashTable::display() const
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "Index "
             << i
             << ": ";

        Node* current =
            table[i];

        while (current != nullptr)
        {
            cout << "["
                 << current->food->getId()
                 << " - "
                 << current->food->getName()
                 << " | Quantity: "
                 << current->food->getQuantity()
                 << "] -> ";

            current =
                current->next;
        }

        cout << "NULL\n";
    }
}


// ======================================
// DESTRUCTOR
// ======================================

FoodHashTable::~FoodHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node* current =
            table[i];

        while (current != nullptr)
        {
            Node* temp =
                current;

            current =
                current->next;

            // Delete only hash-table node
            delete temp;
        }

        table[i] =
            nullptr;
    }
}