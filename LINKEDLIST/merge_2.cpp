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

    Node* mergeLists(Node* l1, Node* l2) {

        Node dummy(0);
        Node* tail = &dummy;

        while(l1 != NULL && l2 != NULL) {

            if(l1->data <= l2->data) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        if(l1 != NULL) tail->next = l1;
        if(l2 != NULL) tail->next = l2;

        return dummy.next;
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

    Node* sortList(Node* head) {

        if(head == NULL || head->next == NULL)
            return head;

        Node* mid = getMid(head);

        Node* right = mid->next;
        mid->next = NULL;

        Node* left = sortList(head);
        right = sortList(right);

        return mergeLists(left, right);
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

    s.push_back(9);
    s.push_back(11);
    s.push_back(155);

    Node* head1 = s.head;

    Solution s2;

    s2.push_back(6);
    s2.push_back(20);
    s2.push_back(4);

    Node* head2 = s2.head;

    cout << "List 1 (unsorted): ";
    s.print(head1);

    cout << "List 2 (unsorted): ";
    s2.print(head2);

    head1 = s.sortList(head1);
    head2 = s2.sortList(head2);

    Node* merged = s.mergeLists(head1, head2);

    cout << "Final Sorted Merged List: ";
    s.print(merged);

    return 0;
}
