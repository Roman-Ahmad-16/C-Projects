#include "FoodLinkedList.h"
#include "FoodHashTable.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// ======================================
// CONSTRUCTOR
// ======================================

FoodLinkedList::FoodLinkedList()
{
    head = nullptr;
}

// ======================================
// ADD FOOD
// ======================================

bool FoodLinkedList::addFood(Food food)
{
    // Prevent duplicate Food ID
    if (searchFood(food.getId()) != nullptr)
    {
        return false;
    }

    Node *newNode =
        new Node(food);

    // Insert at beginning
    newNode->next = head;

    head = newNode;

    return true;
}

// ======================================
// DISPLAY FOODS
// ======================================

void FoodLinkedList::displayFoods() const
{
    if (head == nullptr)
    {
        cout << "Food list is empty.\n";
        return;
    }

    Node *current = head;

    while (current != nullptr)
    {
        current->food.display();

        current = current->next;
    }
}

// ======================================
// SEARCH FOOD
// ======================================

Food *FoodLinkedList::searchFood(int id)
{
    Node *current = head;

    while (current != nullptr)
    {
        if (current->food.getId() == id)
        {
            return &current->food;
        }

        current = current->next;
    }

    return nullptr;
}

// ======================================
// DELETE FOOD
// ======================================

bool FoodLinkedList::deleteFood(int id)
{
    if (head == nullptr)
    {
        return false;
    }

    // Delete first node
    if (head->food.getId() == id)
    {
        Node *temp = head;

        head = head->next;

        delete temp;

        return true;
    }

    Node *current = head;

    while (
        current->next != nullptr &&
        current->next->food.getId() != id)
    {
        current = current->next;
    }

    // Food not found
    if (current->next == nullptr)
    {
        return false;
    }

    Node *temp =
        current->next;

    current->next =
        temp->next;

    delete temp;

    return true;
}

// ======================================
// COUNT FOODS
// ======================================

int FoodLinkedList::countFoods() const
{
    int count = 0;

    Node *current = head;

    while (current != nullptr)
    {
        count++;

        current = current->next;
    }

    return count;
}

// ======================================
// REDUCE QUANTITY
// ======================================

bool FoodLinkedList::reduceQuantity(
    int id,
    int quantity)
{
    Food *food =
        searchFood(id);

    if (food == nullptr)
    {
        return false;
    }

    if (quantity <= 0)
    {
        return false;
    }

    if (food->getQuantity() < quantity)
    {
        return false;
    }

    food->setQuantity(
        food->getQuantity() - quantity);

    return true;
}

// ======================================
// REMOVE FOOD
// Saves a copy before deletion
// ======================================

bool FoodLinkedList::removeFood(
    int id,
    Food &deletedFood)
{
    if (head == nullptr)
    {
        return false;
    }

    // Remove first node
    if (head->food.getId() == id)
    {
        deletedFood =
            head->food;

        Node *temp =
            head;

        head =
            head->next;

        delete temp;

        return true;
    }

    Node *current =
        head;

    while (
        current->next != nullptr &&
        current->next->food.getId() != id)
    {
        current =
            current->next;
    }

    // Food not found
    if (current->next == nullptr)
    {
        return false;
    }

    Node *temp =
        current->next;

    deletedFood =
        temp->food;

    current->next =
        temp->next;

    delete temp;

    return true;
}

// ======================================
// GET FOOD POINTER
// ======================================

Food *FoodLinkedList::getFoodPointer(int id)
{
    return searchFood(id);
}

// ======================================
// LOAD FROM FILE
// ======================================

bool FoodLinkedList::loadFromFile(
    const string &filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        return false;
    }

    string line;

    while (getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        stringstream ss(line);

        string idString;
        string name;
        string quantityString;
        string priceString;

        getline(
            ss,
            idString,
            '|');

        getline(
            ss,
            name,
            '|');

        getline(
            ss,
            quantityString,
            '|');

        getline(
            ss,
            priceString,
            '|');

        int id =
            stoi(idString);

        int quantity =
            stoi(quantityString);

        double price =
            stod(priceString);

        Food food(
            id,
            name,
            quantity,
            price);

        addFood(food);
    }

    file.close();

    return true;
}

// ======================================
// SAVE TO FILE
// ======================================

bool FoodLinkedList::saveToFile(
    const string &filename) const
{
    ofstream file(filename);

    if (!file.is_open())
    {
        return false;
    }

    Node *current =
        head;

    while (current != nullptr)
    {
        file << current->food.getId()
             << "|"
             << current->food.getName()
             << "|"
             << current->food.getQuantity()
             << "|"
             << current->food.getPrice()
             << "\n";

        current =
            current->next;
    }

    file.close();

    return true;
}

// ======================================
// BUILD HASH TABLE
// ======================================

void FoodLinkedList::buildHashTable(
    FoodHashTable &foodTable)
{
    Node *current =
        head;

    while (current != nullptr)
    {
        foodTable.insert(
            &current->food);

        current =
            current->next;
    }
}
// ======================================================
// SORT BY ID
// ======================================================

void FoodLinkedList::sortByID()
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    bool swapped;

    do
    {
        swapped = false;

        Node *current = head;

        while (current->next != nullptr)
        {
            if (current->food.getId() >
                current->next->food.getId())
            {
                Food temp =
                    current->food;

                current->food =
                    current->next->food;

                current->next->food =
                    temp;

                swapped = true;
            }

            current =
                current->next;
        }

    } while (swapped);
}

// ======================================================
// SORT BY NAME
// ======================================================

void FoodLinkedList::sortByName()
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    bool swapped;

    do
    {
        swapped = false;

        Node *current = head;

        while (current->next != nullptr)
        {
            if (current->food.getName() >
                current->next->food.getName())
            {
                Food temp =
                    current->food;

                current->food =
                    current->next->food;

                current->next->food =
                    temp;

                swapped = true;
            }

            current =
                current->next;
        }

    } while (swapped);
}

// ======================================================
// SORT BY PRICE
// ======================================================

void FoodLinkedList::sortByPrice()
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    bool swapped;

    do
    {
        swapped = false;

        Node *current = head;

        while (current->next != nullptr)
        {
            if (current->food.getPrice() >
                current->next->food.getPrice())
            {
                Food temp =
                    current->food;

                current->food =
                    current->next->food;

                current->next->food =
                    temp;

                swapped = true;
            }

            current =
                current->next;
        }

    } while (swapped);
}

// ======================================================
// SORT BY QUANTITY
// ======================================================

void FoodLinkedList::sortByQuantity()
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    bool swapped;

    do
    {
        swapped = false;

        Node *current = head;

        while (current->next != nullptr)
        {
            if (current->food.getQuantity() >
                current->next->food.getQuantity())
            {
                Food temp =
                    current->food;

                current->food =
                    current->next->food;

                current->next->food =
                    temp;

                swapped = true;
            }

            current =
                current->next;
        }

    } while (swapped);
}

// ======================================
// DESTRUCTOR
// ======================================

FoodLinkedList::~FoodLinkedList()
{
    Node *current =
        head;

    while (current != nullptr)
    {
        Node *temp =
            current;

        current =
            current->next;

        delete temp;
    }

    head =
        nullptr;
}