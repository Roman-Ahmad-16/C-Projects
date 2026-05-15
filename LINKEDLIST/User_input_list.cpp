#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	
	Node(int val){
		data = val;
		next = NULL;
	}
};

class List {
	Node* head;
	Node* tail;
	
	public:
		List(){
			head=tail=NULL;
		}
	void push_front(int val){
		Node* newNode = new Node(val);
		if(head == NULL){
			head=tail=newNode;
			return;
		}else{
			newNode->next = head;
			head = newNode;
		}
	}
	
	void push_back(int val){
		Node* newNode = new Node(val);
		if(head == NULL){
			head=tail=newNode;
			return;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
		
	}
	
	void pop_front(){
		if(head==NULL){
			cout<<"List is empty";
			return;
		}else{
			Node* temp = head;
			head = head->next;
			temp->next = NULL;
			
			delete temp;
		}
	}
	
	void pop_back(){
		if(head == tail){
			delete head;
			head = tail = NULL;
			return;
		}else {
			Node* temp = head;
			
			while(temp->next!=tail){
				temp = temp->next;
			}
			temp->next = NULL;
			delete tail;
			tail = temp;
			
		}
	}
	
	void insert(int val , int pos ){
		
		if(pos<0) {
			cout<<"Invalid position";
			return;
		}
		if(pos==0) {
			push_front(val);
			return;
		}
		
		Node* temp = head;
		
		for(int i=0; i<pos-1; i++){
			if(temp==NULL){
				cout<<"Invalid position";
				return;
			}
			
			temp = temp->next;
		}
		
		Node* newNode = new Node(val);
		newNode->next = temp->next;
		temp->next = newNode;
	}
	
	int search(int key ) {
		
		Node *temp = head;	
		int idx = 0;
		
		while(temp!=NULL) {
			if(temp->data == key){
				return idx;
			}
			temp=temp->next;
			idx++;
		}
		return -1;
	}
	
	void deleteValue(int key) {
		
		if(head == NULL){
			cout<<"LL IS EMPTY";
			return;
		}
		
		if(head->data == key ) {
			
			Node* temp =head;
			head = head->next;
			
			delete temp;
			
			if(head == NULL) {
				tail = NULL;
			}
			return;
		}
		
		Node* temp = head;
		Node* prev = NULL;
		
		while(temp!=NULL && temp->data!=key) {
			prev = temp;
			temp=temp->next;
		}
		
		if(temp==NULL) {
			cout<<"Value not found";
			return;
		}
		
		if(temp==tail){
   			tail=prev;
    		prev->next = NULL;
    		delete temp;
    		return;
		}
		prev->next = temp->next;
		delete temp;
	}
	
	void printll(){
		Node* temp = head;
		
		while(temp!=NULL) {
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
	}
};

int main(){
	List ll;
	
//		int n;
//		cout<<"Enter number to print list = ";
//		cin>>n;
//		
//	for(int i=0; i<n; i++) {
//		int val;
//		cout<<"Enter value to add node on start , Value enter at position->"<< i+1 <<" = ";
//		cin>>val;
//		ll.push_front(val);
//	}
//	
//	ll.printll();
	
//	int nu;
//	cout<<"Enter number to delete = ";
//	cin>>nu;
//	ll.deleteValue(nu);
//	ll.printll();
	
//	ll.pop_front();
//	ll.printll();

//	int val;
//	cout<<"Enter value to insert = ";
//	cin>>val;
//	
//	int pos;
//	cout<<"Enter position to insert at = ";
//	cin>>pos;
//	
//	ll.insert(val , pos);
//	ll.printll();

//	cout<<"Index of search item = "<<ll.search(2)<<endl;
	
//	int n;
//	cout<<"Enter number to print list = ";
//	cin>>n;
//	
//	for(int i=0; i<n; i++){
//		int val;
//		cout<<"Enter value to add node on last , Value enter at position -> "<<i+1<<" = ";
//		cin>>val;
//		ll.push_back(val);
//	}
//	
//	ll.printll();
//	
//	ll.pop_back();
//	ll.printll();

	return 0;
}
