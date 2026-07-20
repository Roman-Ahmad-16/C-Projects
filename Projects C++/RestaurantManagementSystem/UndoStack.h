#ifndef UNDO_STACK_H
#define UNDO_STACK_H

#include "Food.h"

class UndoStack
{
private:

    struct Node
    {
        Food food;
        Node* next;

        Node(Food food)
            : food(food), next(nullptr)
        {
        }
    };

    Node* top;

public:

    UndoStack();

    void push(Food food);

    bool isEmpty() const;

    Food* pop();

    void display() const;

    ~UndoStack();
};

#endif