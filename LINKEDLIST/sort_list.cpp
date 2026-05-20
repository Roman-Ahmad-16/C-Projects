#include<iostream>
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

class Solution {
	
public:

    Node* head;
    Node* tail;

    Solution() {
        head = NULL;
        tail = NULL;
    }

    void push_back(int val) {

        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    Node* getMiddle(Node* head) {

        Node* slow = head;
        Node* fast = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node* merge(Node* left, Node* right) {

        if(left == NULL) return right;
        if(right == NULL) return left;

        if(left->data <= right->data) {
            left->next = merge(left->next, right);
            return left;
        }
        else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    Node* mergeSort(Node* head) {

        if(head == NULL || head->next == NULL)
            return head;

        Node* mid = getMiddle(head);

        Node* rightHead = mid->next;
        mid->next = NULL;

        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);

        return merge(left, right);
    }

    void print(Node* head) {

        while(head != NULL) {
            cout << head->data << " -> ";
            head = head->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {

    Solution s;

    s.push_back(5);
    s.push_back(200);
    s.push_back(4);
    s.push_back(1);
    s.push_back(30);

    cout << "Original List: ";
    s.print(s.head);

    s.head = s.mergeSort(s.head);

    cout << "Sorted List: ";
    s.print(s.head);

    return 0;
}
