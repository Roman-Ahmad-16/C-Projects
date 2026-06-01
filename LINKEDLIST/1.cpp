#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

int main()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = head;
    head->prev = fourth;

    cout << "Reverse Traversal: ";

    Node* temp = head->prev;

    do
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    while(temp != head->prev);

    cout << endl;

    return 0;
}
