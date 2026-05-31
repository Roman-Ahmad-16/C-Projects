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
	/	head=tail=NULL;
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
	v*
    Solution s;

    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    s.push_back(5);
    
    cout << "Original List:\n";
    s.printLL(s.head);
    
    Node* middle = s.middle(s.head);
    cout<<"Middle value of List = "<<middle->data;
    
    return 0;
}
