#include <iostream>
using namespace std;

class LibraryMember
{
public:
    virtual int getBorrowLimit()
    {
        return 0;
    }
};

class Student : public LibraryMember
{
public:
    int getBorrowLimit()
    {
        return 3;
    }
};

class Faculty : public LibraryMember
{
public:
    int getBorrowLimit()
    {
        return 8;
    }
};

int main()
{

    LibraryMember *member;

    Student s;
    Faculty f;

    member = &s;
    cout << "Student borrowing limit: "
         << member->getBorrowLimit() << endl;

    member = &f;
    cout << "Faculty borrowing limit: "
         << member->getBorrowLimit() << endl;

    return 0;
}
