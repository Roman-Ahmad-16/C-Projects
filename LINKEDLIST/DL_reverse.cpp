#include<iostream>
using namespace std;
class Node {
	public:
		int data;
		Node* next;
		Node* prev;
		
	Node(int val) {
		data = val;
		next = NULL;
		prev = NULL;
	}
};
class DoublyList {
	Node* head;
	Node* tail;
	
	public:
		DoublyList() {
			head = tail = NULL;
		}
	
	void push_back(int val) {
		Node* newNode = new Node(val);
		
		if(head == NULL) {
			head = tail = newNode;
		}else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}
	l
    void reverseLL() {

        Node* curr = head;
        Node* temp = NULL;

        while(curr != NULL) {

            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }

        temp = head;
        head = tail;
        tail = temp;
    }

	
	
	void printLL() {
		Node* temp = head;
		
		while(temp != NULL) {
			cout<<temp->data<< "->";
			temp = temp->next;
		}
		cout<<"NULL\n";
	}
};
int main() {
	DoublyList dll;
	
	dll.push_back(1);
	dll.push_back(2);
	dll.push_back(3);
	dll.push_back(4);
	dll.push_back(5);
	dll.push_back(6);
	
	cout<<"Original List:\n";
    dll.printLL();

    dll.reverseLL();

    cout<<"\nReversed List:\n";
    dll.printLL();
	
	return 0;
}
