#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    int tortoise = 1, hare = 1;

    cout << "BANG !!!!!\nAND THEY'RE OFF !!!!!\n";

    while (tortoise < 70 && hare < 70)
    {
        int tMove = rand() % 50 + 1;
        if (tMove <= 25)
            tortoise += 3;           
        else if (tMove <= 33)
            tortoise -= 6;           
        else
            tortoise += 1;           

        if (tortoise < 1)
            tortoise = 1;

        int hMove = rand() % 50 + 1;
        if (hMove <= 19)
            ;                        
        else if (hMove <= 27)
            hare += 11;              
        else if (hMove <= 35)
            hare -= 9;               
        else if (hMove <= 45)
            hare += 1;               
        else
            hare -= 2;               

        if (hare < 1)
            hare = 1;

        for (int i = 1; i <= 70; i++)
        {
            if (i == tortoise && i == hare)
            {
                cout << "OUCH!!!";
                i += 6; 
            }
            else if (i == tortoise)
                cout << "T";
            else if (i == hare)
                cout << "H";
            else
                cout << " ";
        }
        cout << endl;
    }

    if (tortoise >= 70 && hare >= 70)
        cout << "It's a tie\n";
    else if (tortoise >= 70)
        cout << "TORTOISE WINS!!!\n";
    else
        cout << "Hare wins\n";

    return 0;
}

