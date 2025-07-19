#include<iostream>
#include<math.h>
using namespace std;

class quadratic {
private:
    double a, b, c;
    
public:
    quadratic() {
        cout << "\nEnter The Coffient : ";
        cout << "\nEnter The Value Of A :";
        cin >> a;
        if (a == 0) {
            cout << "\nThe Value Of A Is Now 1 \n";
            a = 1;
        }
        cout << "\nEnter The Value Of B :";
        cin >> b;
        cout << "\nEnter The Value Of C :";
        cin >> c;
    }
    
    void print() {
        cout << a << "x^2 + " << b << "x + " << c << " = @\n";
    }
    
    void solve() {
        double d = b*b - 4*a*c;
        if(d > 0) {
            double r1 = (-b - sqrt(d))/(2*a);
            double r2 = (-b + sqrt(d))/(2*a);
            cout << "two real roots : " << r1 << " and " << r2 << endl;
        }
        else if (d == 0) {
            double r = (-b - sqrt(d))/(2*a);
            cout << "one real root : " << r << endl;
        }
        else {
            cout << "no real roots";
        }
    }
};

int main() {
    quadratic q;
    q.print();
    q.solve();
    return 0;
}
