#include <iostream>
using namespace std;

class Node 
{
public:
    int get() 
	{ 
	return object; 
	};
    void set(int object) 
	{ 
	this->object = object; 
	};

    Node* getNext() 
	{ 
	return nextNode; 
	};
    void setNext(Node* nextNode) 
	{ 
	this->nextNode = nextNode; 
	};

private:
    int object;
    Node* nextNode;
};

class CircularLinkedList {
public:
    CircularLinkedList() 
	{
        head = new Node(); // Create head node
        head->setNext(NULL); // Set next of head node to NULL
        currentnode = NULL; // Initialize currentnode pointer to NULL
        lastcurrentnode = NULL; // Initialize lastcurrentnode pointer to NULL
    }

    void addNode(int object) 
	{
        Node* newNode = new Node(); // Create a new node
        newNode->set(object);

        if (head->getNext() == NULL) // If list is empty 
		{ 
            head->setNext(newNode);
            newNode->setNext(head);
            currentnode = newNode;
            lastcurrentnode = head;
        } 
		else 
		{
            newNode->setNext(currentnode->getNext());
            currentnode->setNext(newNode);
            lastcurrentnode = currentnode;
            currentnode = newNode;
        }
    size++;
	}

    void removeNode() {
        if (currentnode == NULL) 
		{
            cout << "No node to remove." << endl;
            return;
        }

        if (currentnode == head->getNext()) // If removing the first node
		{ 
            head->setNext(currentnode->getNext());
            delete currentnode;
            currentnode = head->getNext();
            lastcurrentnode = head;
        } 
		else 
		{
            lastcurrentnode->setNext(currentnode->getNext());
            delete currentnode;
            currentnode = lastcurrentnode->getNext();
        }
    size--;
	}
	int length()
	{
		return size;	
	}
    void displayList() 
	{
        if (head->getNext() == NULL) 
		{
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head->getNext(); // Start from the first node after head
        cout << "Circular Linked List: ";
        while (temp != head) 
		{ // Traverse until we reach back to head
            cout << temp->get() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
    
    int get()
    {
    	return getNext();
	}

public:
    int size = 0;
	Node* head;
    Node* currentnode;
    Node* lastcurrentnode;
};

int main() {
    CircularLinkedList myList;
	int N, m, q;    
    cout<<"Enter the length of the list"<<endl;
    cin>>N;
    
	// Adding nodes to the circular linked list
    for (int a = 1; a <= N; a++)
    {
    	cout<<"Enter the value in list"<<endl;
    	cin>>m;
    	myList.addNode(m);	
	}
	cout<<"Length of the list is: "<<myList.length()<<endl;
    
    cout<<"Enter the quantum size for Leader Selection"<<endl;
    cin>>q;
    
    while( myList.length() > 1 )
    {
    	for(int j = 1; j <= q; j++)
    	{
    		cout<<"Removed Node "<< myList.get();
			myList.removeNode();
		}
    	
	}
    // Displaying the circular linked list
    myList.displayList();

//    // Removing the current node (2)
//    myList.removeNode();
//	
//	cout<<"Length of the list is: "<<myList.length()<<endl;
//    // Displaying the circular linked list after removal
//    myList.displayList();

    return 0;
}

