#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
    	data = val;
        next = NULL;
    }
};

class Stack {

private:
    Node* head;

public:
    Stack() {
        head = NULL;
    }

    void push(int val) {

        Node* newNode = new Node(val);

		newNode->next = head;
		head = newNode;
    }

    void pop() {

        if (head == NULL) {
            cout << "Stack underflow" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;  
        delete temp;
    }

    int top() {

        if (head == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main() {

    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.top() << endl;

    stack.pop();
    cout << "Top element after pop is: " << stack.top() << endl;

    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}
