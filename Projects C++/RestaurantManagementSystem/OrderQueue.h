#ifndef ORDER_QUEUE_H
#define ORDER_QUEUE_H

#include "Order.h"

class OrderQueue
{

private:
    struct Node
    {
        Order order;
        Node *next;

        Node(Order order)
            : order(order), next(nullptr)
        {
        }
    };

    Node *front;
    Node *rear;
    int orderCount;

public:
    OrderQueue();

    void enqueue(Order order);
    bool dequeue();

    Order *peek();

    bool isEmpty() const;

    int size() const;

    void displayOrders() const;

    ~OrderQueue();
};

#endif