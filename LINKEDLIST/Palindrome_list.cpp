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

    void push_back(int val){

        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    Node* getMid(Node* head) {

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node* reverse(Node* head) {

        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL) {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(Node* head) {

        if(head == NULL || head->next == NULL){
            return true;
		}
		
        Node* mid = getMid(head);

        Node* secondHalf = reverse(mid);

        Node* firstHalf = head;

        while(secondHalf != NULL) {

            if(firstHalf->data != secondHalf->data)
                return false;

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
    
    void print(Node* head) {

	Node* temp = head;
	
    while(temp != NULL) {

        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}
};



int main() {

    Solution ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(2);
	ll.push_back(2);
	ll.push_back(1);
	
    cout << "Linked List: ";

    ll.print(ll.head);

    if(ll.isPalindrome(ll.head)){
        cout << "Result: Palindrome List" << endl;
    }else{
        cout << "Result: Not Palindrome" << endl;
	}
	
    return 0;
}
