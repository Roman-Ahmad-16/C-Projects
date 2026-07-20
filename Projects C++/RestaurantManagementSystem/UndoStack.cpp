#include "UndoStack.h"
#include <iostream>

using namespace std;

UndoStack::UndoStack()
{
    top = nullptr;
}

void UndoStack::push(Food food)
{
    Node* newNode =
        new Node(food);

    newNode->next = top;

    top = newNode;
}

Food* UndoStack::pop()
{
    if (top == nullptr)
    {
        return nullptr;
    }

    Node* temp = top;

    Food* deletedFood =
        new Food(temp->food);

    top = top->next;

    delete temp;

    return deletedFood;
}

bool UndoStack::isEmpty() const
{
    return top == nullptr;
}

void UndoStack::display() const
{
    if (top == nullptr)
    {
        cout << "Undo stack is empty.\n";
        return;
    }

    cout << "\n===== DELETED FOOD HISTORY =====\n";

    Node* current = top;

    while (current != nullptr)
    {
        current->food.display();

        current = current->next;
    }
}

UndoStack::~UndoStack()
{
    while (top != nullptr)
    {
        Node* temp = top;

        top = top->next;

        delete temp;
    }
}