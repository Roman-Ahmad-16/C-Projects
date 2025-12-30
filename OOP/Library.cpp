#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string section;         

    static int csCount;
    static int engCount;
    static int artsCount;
    static int totalCount;

public:
    Book(string t, string s) {
        title = t;
        section = s;

        if (section == "CS")
            csCount++;
        else if (section == "ENG")
            engCount++;
        else if (section == "Arts")
            artsCount++;

        totalCount++;

        cout << "Book added: " << title << " (" << section << ")\n";
    }

    ~Book() {
        if (section == "CS")
            csCount--;
        else if (section == "ENG")
            engCount--;
        else if (section == "Arts")
            artsCount--;

        totalCount--;

        cout << "Book removed: " << title << endl;
    }

    static void showInventory() {
        cout << "\n--- Library Status ---\n";
        cout << "CS Books: " << csCount << endl;
        cout << "ENG Books: " << engCount << endl;
        cout << "Arts Books: " << artsCount << endl;
        cout << "Total Books: " << totalCount << endl;
        cout << "---------------------\n";
    }
};

int Book::csCount = 0;
int Book::engCount = 0;
int Book::artsCount = 0;
int Book::totalCount = 0;

int main() {
    cout << "Library System Started\n";

    Book::showInventory();

    Book b1("C++ Guide", "CS");
    Book b2("Java Basics", "CS");
    Book b3("English Grammar", "ENG");

    Book::showInventory();

    Book b4("Art History", "Arts");
    Book b5("Data Structures", "CS");

    Book::showInventory();

    cout << "\nEnd of program\n";
    
    return 0;
}

