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

    Node* getMid(Node* head) {

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

        Node* mid = getMid(head);

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

    s.push_back(19);
    s.push_back(11);
    s.push_back(155);

    Node* head1 = s.head;

    Solution s2;

    s2.push_back(6);
    s2.push_back(20);
    s2.push_back(490);

    Node* head2 = s2.head;

    cout << "List 1 (unsorted): ";
    s.print(head1);

    cout << "List 2 (unsorted): ";
    s2.print(head2);

    head1 = s.mergeSort(head1);

    head2 = s2.mergeSort(head2);

    Node* merged = s.merge(head1, head2);

    cout << "Final Sorted Merged List: ";

    s.print(merged);

    return 0;
}
