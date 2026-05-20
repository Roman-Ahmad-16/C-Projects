#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
	stack<int> s1,s2;
public:
	void enqueue(int customer) {
		s1.push(customer);
	}
    int dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

		if(s2.empty()) {
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}

        int frontCustomer = s2.top();
        s2.pop();
        return frontCustomer;
    }

    bool isEmpty() {
        return (s1.empty() && s2.empty());
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue(104);

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;
}
