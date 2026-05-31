#include <iostream>
using namespace std;

class  Stack
{
	private:
		int current; 
       	int   size; 
       	int   A[10];
    
	public:
        Stack() 
		{ 
			size = 10; current = -1;
		} 
		void push(int x)
		{ 
			A[++current] = x;
		} 
        int pop()
		{ 
			return A[current--];
		} 
        int top()
		{ 
			return A[current];
		} 
		int isEmpty()
		{
			return ( current == -1 );
		} 
		int isFull() 
		{ 
			return ( current == size-1);
		} 

};

int main()
{
	Stack stack; 
 
    for(int i = 0; i < 12; i++)
    { 
		if(!stack.isFull())  
		{
			stack.push(i); 
			cout<<"Push value is = "<<i<<endl;
     	}else 
         	cout <<endl<<"Stack is full, can't insert new element"<<endl;
    } 
    
	for(int i=0 ; i < 12 ; i++)
    {
        if(!stack.isEmpty()) 
		{
			cout <<endl<< "The popped element = " << stack.pop();
        }else{
			cout <<endl<<"Stack is empty, can't pop"<<endl; 
		}
    }
    return 0;
}
