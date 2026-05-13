#include <iostream>
using namespace std;

class OldPhone {
public:
    // NO VIRTUAL KEYWORD HERE
    void takePhoto() {
        std::cout << "Taking a grainy Black & White photo..." << std::endl;
    }
};

class SmartPhone : public OldPhone {
public:
    void takePhoto() {
        std::cout << "Taking a 4K Color photo with AI features!" << std::endl;
    }
};

int main() {
    // We have a SmartPhone object
   
    OldPhone* p;
    SmartPhone m;
    p = &m;
    p->takePhoto();
    m.takePhoto();
     return 0;
}

