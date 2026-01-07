#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string category; 
    
    static int csCount;
    static int engCount;
    static int artsCount;
    static int totalBooks;

public:
    Book(string cat) {
        category = cat;
        totalBooks++;
        
        if (category == "CS") {
            csCount++;
        } else if (category == "ENG") {
            engCount++;
        } else if (category == "Arts") {
            artsCount++;
        }
    }

    ~Book() {
        totalBooks--;
        
        if (category == "CS") {
            csCount--;
        } else if (category == "ENG") {
            engCount--;
        } else if (category == "Arts") {
            artsCount--;
        }
        cout << "Book from " << category << " removed. Remaining Total: " << totalBooks << endl;
    }

    static void displayInventory() {
        cout << "\n--- Current Library Inventory ---" << endl;
        cout << "CS Books:   " << csCount << endl;
        cout << "ENG Books:  " << engCount << endl;
        cout << "Arts Books: " << artsCount << endl;
        cout << "TOTAL BOOKS:" << totalBooks << endl;
        cout << "---------------------------------\n" << endl;
    }
};

int Book::csCount = 0;
int Book::engCount = 0;
int Book::artsCount = 0;
int Book::totalBooks = 0;

int main() {
    Book::displayInventory();

    cout << "Adding books..." << endl;
    Book b1("CS");
    Book b2("CS");
    Book b3("ENG");
    Book b4("Arts");

    Book::displayInventory();
{
        cout << "Creating a temporary CS book..." << endl;
        Book temp("CS"); 
        Book::displayInventory();
        cout << "Exiting temporary block (destroying temp book)..." << endl;
    
}
    Book::displayInventory();

    return 0;
}