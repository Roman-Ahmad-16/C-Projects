#include <iostream>
using namespace std;
class Heart
{
public:
    int rate;
    string type;

    Heart(int r, string t)
    {
        rate = r;
        type = t;
        cout << "Heart created: " << type << " with rate " << rate << " BPM" << endl;
    }

    ~Heart()
    {
        cout << "Heart destroyed: " << type << endl;
    }
    void beat()
    {
        cout << "Heart is beating at " << rate << " BPM" << endl;
    }
};

class Human
{
    Heart h;

public:
    string name;
    int age;

    Human(string n, int a, int r, string t) : h(r, t)
    {
        name = n;
        age = a;
        cout << "Human created: " << name << ", Age: " << age << endl;
    }
    ~Human()
    {
        cout << "Human destroyed: " << name << endl;
    }
    void live()
    {
        cout << name << " is alive." << endl;
        h.beat(); 
    }
};
int main()
{
    Human h1("Ali", 25, 80, "Normal");
    h1.live();
    cout << "End of main function." << endl;
}
