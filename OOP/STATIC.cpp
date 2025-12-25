#include <iostream>
using namespace std;

class Math {
public:
    static int square(int x) {  // static function
        return x * x;
    }
};

int main() {
    cout << "Square of 5: " << Math::square(5) << endl;
    cout << "Square of 10: " << Math::square(10) << endl;
}
