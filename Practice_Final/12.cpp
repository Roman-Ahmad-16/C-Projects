#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    string name;
    int roll_no;
    int *marks; // dynamically allocated array
    string status;

    Student(string a, int b, int *c, string d)
    {
        name = a;
        roll_no = b;
        status = d;

        marks = new int[5]; // allocate memory in heap
        for (int i = 0; i < 5; i++)
        {
            marks[i] = c[i];
        }
    }

    void display_info()
    {
        cout << "NAME :: " << name << endl;
        cout << "ROLL_NO :: " << roll_no << endl;
        cout << "MARKS :: ";
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << " ";
        }
        cout << "\nSTATUS :: " << status << endl;
    }

    ~Student() // destructor to free memory
    {
        delete[] marks;
    }
};

int main()
{
    int obt_marks = 0;
    int *marks = new int[5]; // dynamic allocation for input marks
    int total_marks = 500;
    string status;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter marks for subject " << i + 1 << ": ";
        cin >> marks[i];
        obt_marks += marks[i];
    }

    cout << "TOTAL MARKS :: " << total_marks << endl;
    cout << "OBTAIN MARKS = " << obt_marks << endl;

    float percentage = (obt_marks / (float)total_marks) * 100;
    status = (percentage >= 60) ? "Pass" : "Fail";

    Student *st = new Student("Roman", 295, marks, status);

    ofstream write("Recor.txt");
    write << st->name << endl;
    write << st->roll_no << endl;
    for (int i = 0; i < 5; i++)
    {
        write << marks[i] << " ";
    }
    write << endl;
    write << percentage << endl;
    write << st->status << endl;
    write.close();

    delete[] marks; // input marks ka array free kar rahe hain

    ifstream read("Recor.txt");

    string a_name, a_status;
    int a_roll_no;
    int *a_marks = new int[5]; // dynamic allocation for reading
    float a_percentage;

    read >> a_name;
    read >> a_roll_no;
    for (int i = 0; i < 5; i++)
    {
        read >> a_marks[i];
    }
    read >> a_percentage;
    read >> a_status;

    read.close();

    Student *read_student = new Student(a_name, a_roll_no, a_marks, a_status);
    read_student->display_info();
    cout << "PERCENTAGE : " << a_percentage << "%" << endl;

    delete[] a_marks;     // free read marks
    delete read_student;  // free student object
    delete st;            // free original student object

    return 0;
}

