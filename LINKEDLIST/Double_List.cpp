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

class DoublyList
{
private:
    Node* head;
    Node* tail;

public:
    DoublyList()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL) {
            cout << "List is Empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        delete temp;
    }

    void push_back(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back()
    {
        if (head == NULL) {
            cout << "List is Empty" << endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }

        delete temp;
    }

    void insert(int val, int pos)
    {
        if (pos < 0) {
            cout << "Invalid Position" << endl;
            return;
        }

        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL) {
                cout << "Invalid Position" << endl;
                return;
            }

            temp = temp->next;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;

        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    void deleteValue(int key)
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Value Not Found" << endl;
            return;
        }

        if (temp == head) {
            pop_front();
            return;
        }

        if (temp == tail) {
            pop_back();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    int search(int key)
    {
        Node* temp = head;
        int index = 0;

        while (temp != NULL)
        {
            if (temp->data == key) {
                return index;
            }

            temp = temp->next;
            index++;
        }

        return -1;
    }

    void printLL()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void printReverse()
    {
        Node* temp = tail;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyList dll;

    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);
    dll.push_back(40);

    cout << "Original List:" << endl;
    dll.printLL();

    cout << "\nAfter Inserting 25 at Position 2:" << endl;
    dll.insert(25, 2);
    dll.printLL();

    cout << "\nSearching 30:" << endl;
    cout << "Index = " << dll.search(30) << endl;

    cout << "\nAfter Deleting 25:" << endl;
    dll.deleteValue(25);
    dll.printLL();

    cout << "\nReverse Traversal:" << endl;
    dll.printReverse();

    return 0;
}
