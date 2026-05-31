#include<iostream>
using namespace std;
class Node{
  	public:
  		int data;
  		Node* next;
  	
  	Node(int val){
  		data = val ;
  		next = NULL;
	  }
};
class CircularList{
	public:
		Node* head;
		Node* tail;
		
	CircularList(){
		head = tail = NULL;
	}
	
	void insert_head(int val) {
		Node* newNode = new Node(val);
		
		if(tail == NULL){
			head = tail = newNode;
			tail->next = head;
		} else {
			newNode->next = head;
			head = newNode;
			tail->next = head;
		}
	}
	
	void insert_tail(int val) {
		Node* newNode = new Node(val);
		
		if(tail == NULL) {
			head = tail = newNode;
			tail->next = head;
		} else {
			newNode->next = head ;
			tail->next = newNode;
			tail = newNode;
		}
	}
	
	void delete_head() {
		if(head == NULL){
			return;
		} else if (head==tail) {
			delete head;
			head = tail = NULL;
		} else {
			Node* temp = head ;
			head = head->next;
			tail->next = head;
			
			temp->next = NULL; 
			delete temp;
		}
	}
	
	void delete_tail() {
		if(head==NULL) {
			return;
		} else if(head==tail){
			delete head;
			head = tail = NULL;
		} else {
			Node* temp = tail;
			
			Node* prev = head;
			while(prev->next != tail) {
				prev = prev->next;
			}
			
			tail = prev;
			tail->next = head;
			
			temp->next = NULL;
			delete temp;
		}
	}
	void print(){
		
		if (head == NULL ) {
			return;
		}
		
		cout<<head->data<<"->";
		Node* temp = head->next;
		
		while(temp!=head) {
			cout<<temp->data<<"->";
			temp = temp->next;
		}
		cout<<temp->data<<endl;
	}
};

int main(){
	
	CircularList CL;
	
	CL.insert_head(4);
	CL.insert_head(3);
	CL.insert_head(2);
	CL.insert_head(1);
	
	CL.print();
	
	
//	CL.insert_tail(4);
//	CL.insert_tail(3);
//	CL.insert_tail(2);
//	CL.print();
//	
//	CL.delete_head();
//	CL.print();
//	
//	CL.delete_tail();
//	CL.print();
	
	return 0;
}
