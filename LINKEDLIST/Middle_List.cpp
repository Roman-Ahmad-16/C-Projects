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
		Node* middle(Node* head) {
			
			Node* slow = head;
			Node* fast = head;
			
			while(fast != NULL && fast->next != NULL) {
				
				slow = slow->next;
				fast = fast->next->next; 
			}
			return slow;
		}
		
		void printLL(Node* head) {
			
			Node* temp = head;
			
			while(temp != NULL ) {
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			cout<<"NULL"<<endl;
		}
};
int main(){
	
	Node* head = new Node(1);
	
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    
    Solution s;
    
    cout << "Original List:\n";
    s.printLL(head);
    
    Node* middle = s.middle(head);
    cout<<"Middle value of List = "<<middle->data;
    
    return 0;
}
