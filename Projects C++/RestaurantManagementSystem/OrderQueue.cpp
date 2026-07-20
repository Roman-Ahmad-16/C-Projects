#include "OrderQueue.h"

#include <iostream>

using namespace std;

// ======================================
// CONSTRUCTOR
// ======================================

OrderQueue::OrderQueue()
{
    front =
        nullptr;

    rear =
        nullptr;

    orderCount =
        0;
}

// ======================================
// ENQUEUE
// ======================================

void OrderQueue::enqueue(Order order)
{
    Node *newNode =
        new Node(order);

    // Queue is empty
    if (rear == nullptr)
    {
        front =
            newNode;

        rear =
            newNode;
    }
    else
    {
        rear->next =
            newNode;

        rear =
            newNode;
    }

    orderCount++;
}

// ======================================
// DEQUEUE
// ======================================

bool OrderQueue::dequeue()
{
    if (front == nullptr)
    {
        return false;
    }

    Node *temp =
        front;

    front =
        front->next;

    delete temp;

    if (front == nullptr)
    {
        rear =
            nullptr;
    }

    orderCount--;

    return true;
}

// ======================================
// PEEK
// ======================================

Order *OrderQueue::peek()
{
    if (front == nullptr)
    {
        return nullptr;
    }

    return &front->order;
}

// ======================================
// IS EMPTY
// ======================================

bool OrderQueue::isEmpty() const
{
    return front == nullptr;
}

// ======================================
// SIZE
// ======================================

int OrderQueue::size() const
{
    return orderCount;
}

// ======================================
// DISPLAY ORDERS
// ======================================

void OrderQueue::displayOrders() const
{
    if (front == nullptr)
    {
        cout << "Order queue is empty.\n";

        return;
    }

    Node *current =
        front;

    while (current != nullptr)
    {
        current->order.display();

        current =
            current->next;
    }
}

// ======================================
// DESTRUCTOR
// ======================================

OrderQueue::~OrderQueue()
{
    while (front != nullptr)
    {
        Node *temp =
            front;

        front =
            front->next;

        delete temp;
    }

    rear =
        nullptr;

    orderCount =
        0;
}