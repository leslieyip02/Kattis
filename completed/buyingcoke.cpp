#include <iostream>
#include <algorithm>
using namespace std;

int t, c, n1, n5, n10;

int buy_coke()
{
    int coins = 0;

    if (c <= n10)
        return c;

    c -= n10;
    coins += n10;
    if (c >= n5)
    {
        // find number of tens to combine with 3 ones to get back 1 five
        int extraFives = min(c - n5, n10);
        n5 += extraFives;
        
        // add 3 crowns for each set
        coins += extraFives * 3;
        coins += n5 * 4;
        coins += (c - n5) * 8;
    }
    else
    {
        // pair as many fives
        int pairedFives = min(n5 - c, c);
        coins += pairedFives * 2;
        coins += (c - pairedFives) * 4;
    }

    return coins;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> c >> n1 >> n5 >> n10;
        cout << buy_coke() << endl;        
    }

    return 0;
}