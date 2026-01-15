#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    string *subjects;
    int *marks;
    int size;

public:
    Student(string n, string sub[], int m[], int s)
    {
        name = n;
        size = s;

        subjects = new string[size];
        marks = new int[size];

        for (int i = 0; i < size; i++)
        {
            subjects[i] = sub[i];
            marks[i] = m[i];
        }
    }

    Student(const Student &other)
    {
        name = other.name + " (Copy)";
        size = other.size;

        subjects = new string[size];
        marks = new int[size];

        for (int i = 0; i < size; i++)
        {
            subjects[i] = other.subjects[i];
            marks[i] = other.marks[i];
        }
        cout << ">> Deep Copy Constructor called for " << name << endl;
    }

    ~Student()
    {
        delete[] subjects;
        delete[] marks;
    }

    void display() const
    {
        cout << "---------------------------------" << endl;
        cout << "Student Name: " << name << endl;
        cout << "Subjects & Marks:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "  " << subjects[i] << ": " << marks[i] << endl;
        }
        cout << "---------------------------------" << endl;
    }
};

int main()
{

    string sub1[] = {"Math", "Physics", "Chemistry", "English", "CS"};
    int marks1[] = {90, 85, 88, 75, 95};

    string sub2[] = {"Calculus", "Biology", "History", "Urdu", "Ethics"};
    int marks2[] = {50, 60, 55, 70, 65};

    string sub3[] = {"Algebra", "Geography", "Physics", "Art", "Sports"};
    int marks3[] = {88, 77, 91, 80, 100};

    string sub4[] = {"Economics", "Stats", "Accounts", "Business", "Marketing"};
    int marks4[] = {40, 45, 50, 60, 55};

    string sub5[] = {"Zoology", "Botany", "Chem", "English", "Islamiyat"};
    int marks5[] = {92, 94, 89, 85, 90};

    cout << "Creating 5 Students..." << endl;
    Student s1("Ali", sub1, marks1, 5);
    Student s2("Sara", sub2, marks2, 5);
    Student s3("Ahmed", sub3, marks3, 5);
    Student s4("Zain", sub4, marks4, 5);
    Student s5("Hina", sub5, marks5, 5);

    s1.display();
    s2.display();
    s3.display();
    s4.display();
    s5.display();

    cout << "\n=== DEMONSTRATING DEEP COPY ===" << endl;
    Student s1Copy = s1;

    s1Copy.display();

    return 0;
}