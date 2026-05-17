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
		
	void push_front(int val ) {
		Node* newNode = new Node(val);
		
		if(head==NULL) {
			head = tail = newNode;
		}else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	
	void pop_front() {
		
		if(head == NULL) {
			cout<<"List is empty"<<endl;
			return;
		}
		Node* temp = head;
		
		head = head->next;
		
		if(head != NULL) {
			head->prev = NULL;
		}
		temp->next = NULL;
		delete temp;
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
	
	void pop_back() {
		
		if(head == NULL ){
			cout<<"LIST IS EMPTY"<<endl;
			return;
		}
		     Node* temp = tail;
		     
		     tail = tail->prev;
		     if(tail != NULL) {
		     	tail->next = NULL;
			 }
			 temp->prev = NULL;
			 delete temp;
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
	
//	dll.push_front(3);
//	dll.push_front(2);
//	dll.push_front(1);
//	
//	dll.printLL();
	
//	dll.pop_front();
//	dll.printLL();
	
//	dll.pop_back();
//	dll.printLL();
	
	dll.push_back(1);
	dll.push_back(2);
	dll.push_back(3);
	dll.push_back(4);
	dll.push_back(5);
	dll.push_back(6);
	
	dll.printLL();
	
	return 0;
}
