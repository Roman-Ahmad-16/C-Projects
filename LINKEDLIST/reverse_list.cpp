#include<iostream>
using namespace std;
class Node {
	public:
		int data;
		Node* next;
	Node(int val){
		data = val;
		next = NULL;
	}
};
class Solution {
	public:
		
	Node* head;
	Node* tail;
	
	Solution(){
		head=tail=NULL;
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
		Node* reverseList(Node* head) {
			
			Node* prev = NULL;
			Node* curr = head;
			Node* next = NULL;
			
			while(curr != NULL ) {
				
				next = curr->next;
				curr->next = prev;
				
				prev = curr;
				curr = next;
			}
			return prev;
		}
		
		void print (Node* head) {
			
			Node* temp = head;
			
			while(temp != NULL ) {
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			cout<<"Null\n";
		}
};
int main(){
	
    Solution s;

    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    s.push_back(5);
	
	cout << "Original List:\n";
	s.print(s.head);
	
	s.head = s.reverseList(s.head);
	
	cout << "Reversed List:\n";
	s.print(s.head);
	
	return 0;
}
