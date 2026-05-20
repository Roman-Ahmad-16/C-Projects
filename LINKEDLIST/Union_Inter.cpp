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

class LinkedList {

private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    Node* getHead() {
        return head;
    }

    void print() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

bool search(Node* head, int key) {

    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

Node* intersection(Node* A, Node* B) {

    Node* C = NULL;
    Node* tailC = NULL;

    while (A != NULL) {

        if (search(B, A->data)) {
            Node* newNode = new Node(A->data);
            
            if (C == NULL) {
                C = tailC = newNode;
            }else {
                tailC->next = newNode;
                tailC = newNode;
            }
        }
        A = A->next;
    }
    return C;
}

Node* unionList(Node* A, Node* B) {

    Node* D = NULL;
    Node* tailD = NULL;

    Node* temp = A;

    while (temp != NULL) {

        Node* newNode = new Node(temp->data);

        if (D == NULL) {
            D = tailD = newNode;
        }
        else {
            tailD->next = newNode;
            tailD = newNode;
        }

        temp = temp->next;
    }

    temp = B;

    while (temp != NULL) {

        if (!search(D, temp->data)) {
            Node* newNode = new Node(temp->data);

            if (D == NULL) {
                D = tailD = newNode;
            }else {
                tailD->next = newNode;
                tailD = newNode;
            }
        }
        temp = temp->next;
    }
    return D;
}

void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {

    LinkedList A, B;

    int arrA[] = {3, 7, 10, 15, 16, 9, 22, 17, 32};
    int arrB[] = {16, 2, 9, 13, 47, 8, 10, 1, 28};

    for (int i = 0; i < 9; i++) {
        A.push_back(arrA[i]);
        B.push_back(arrB[i]);
    }

    cout << "List A: ";
    A.print();

    cout << "List B: ";
    B.print();

    Node* C = intersection(A.getHead(), B.getHead());

    cout << "Common Elements (C): ";
    print(C);

    Node* D = unionList(A.getHead(), B.getHead());

    cout << "Union without duplicates (D): ";
    print(D);

    return 0;
}
