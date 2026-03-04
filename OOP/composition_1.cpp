#include <iostream>
using namespace std;
class Room
{
    int roomNo;
    string type;

public:
    Room(int r, string t)
    {
        roomNo = r;
        type = t;
        cout << "Room created: " << type << " (" << roomNo << ")" << endl;
    }
    ~Room()
    {
        cout << "Room destroyed: " << roomNo << endl;
    }
    void showRoom()
    {
        cout << "Room No: " << roomNo << ", Type: " << type << endl;
    }
};
class House
{
    Room r; // Composition
    string address;

public:
    House(string a, int rn, string rt) : r(rn, rt)
    {
        address = a;
        cout << "House created at: " << address << endl;
    }
    ~House()
    {
        cout << "House destroyed at: " << address << endl;
    }
    void display()
    {
        cout << "House Address: " << address << endl;
        r.showRoom();
    }
};
int main()
{
    House h("Street 10, Lahore", 1, "Bedroom");
    h.display();
}
