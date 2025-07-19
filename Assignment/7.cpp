#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Initialize random seed based on current time
    srand(time(0));

    int tortoise = 1, hare = 1;

    cout << "BANG !!!!!\nAND THEY'RE OFF !!!!!\n";

    while (tortoise < 70 && hare < 70)
    {
        // Move tortoise
        int tMove = rand() % 50 + 1;
        if (tMove <= 25)
            tortoise += 3;           // Fast plod
        else if (tMove <= 33)
            tortoise -= 6;           // Slip
        else
            tortoise += 1;           // Slow plod

        if (tortoise < 1)
            tortoise = 1;

        // Move hare
        int hMove = rand() % 50 + 1;
        if (hMove <= 19)
            ;                        // Sleep, no move
        else if (hMove <= 27)
            hare += 11;              // Big hop
        else if (hMove <= 35)
            hare -= 9;               // Big slip
        else if (hMove <= 45)
            hare += 1;               // Small hop
        else
            hare -= 2;               // Small slip

        if (hare < 1)
            hare = 1;

        // Print track
        for (int i = 1; i <= 70; i++)
        {
            if (i == tortoise && i == hare)
            {
                cout << "OUCH!!!";
                i += 6; // Skip next 6 positions to fit "OUCH!!!"
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

    // Determine and print the result
    if (tortoise >= 70 && hare >= 70)
        cout << "It's a tie\n";
    else if (tortoise >= 70)
        cout << "TORTOISE WINS!!!\n";
    else
        cout << "Hare wins\n";

    return 0;
}

