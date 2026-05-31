#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList
{
private:
    Node* head;
    Node* tail;
    int size;

public:
    CircularLinkedList()
    {
        head = tail = NULL;
        size = 0;
    }

    void addNode(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }

        size++;
    }

    int length()
    {
        return size;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }

		cout<<head->data<<"->";
		Node* temp = head->next;
		
		while(temp!=head) {
			cout<<temp->data<<"->";
			temp = temp->next;
		}
		cout<<temp->data<<endl;

        cout << endl;
    }

    int josephus(int q)
    {
        if (head == NULL)
            return -1;

        Node* current = head;
        Node* previous = tail;

        while (size > 1)
        {
            for (int i = 1; i < q; i++)
            {
                previous = current;
                current = current->next;
            }

            cout << "Removed Node: " << current->data << endl;

            if (current == head)
            {
                head = head->next;
                tail->next = head;
            }

            if (current == tail)
            {
                tail = previous;
            }

            previous->next = current->next;

            Node* temp = current;
            current = current->next;

            delete temp;
            size--;
        }

        head = current;
        tail = current;
        current->next = current;

        return current->data;
    }
};

int main()
{
    CircularLinkedList myList;

    int N, value, q;

    cout << "Enter number of nodes: ";
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;

        myList.addNode(value);
    }

    cout << "\nOriginal Circular List: ";
    myList.display();

    cout << "\nEnter Quantum Size (q): ";
    cin >> q;

    int leader = myList.josephus(q);

    cout << "\nLeader / Survivor Node = " << leader << endl;

    return 0;
}
