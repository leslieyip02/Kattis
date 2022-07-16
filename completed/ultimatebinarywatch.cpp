#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool display[4][4];
    string time;
    cin >> time;
    
    for (int i = 0; i < 4; i++)
    {
        int digit = time[i];
        for (int j = 0; digit != 0 && j < 4; j++)
        {
            display[3 - j][i] = digit % 2;
            digit /= 2;
        }
    }

    for (int i = 0; i < 4; i++)
        cout << (display[i][0] ? "* " : ". ")
            << (display[i][1] ? "*   " : ".   ")
            << (display[i][2] ? "* " : ". ")
            << (display[i][3] ? "*\n" : ".\n");

    return 0;
}