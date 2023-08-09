#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int ones = 0;
    int twos = 0;

    unsigned long long swaps = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            swaps += ones + twos;
        } 
        else if (s[i] == '1')
        {
            swaps += twos;
            ones++;
        }
        else
        {
            twos++;
        }
    }

    cout << swaps << '\n';

    return 0;
}