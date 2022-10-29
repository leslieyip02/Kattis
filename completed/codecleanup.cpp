#include <iostream>
using namespace std;

int main()
{
    int n, d;
    bool y[365] = { false };

    cin >> n;
    while (n--)
    {
        cin >> d;
        y[d - 1] = true;
    }

    int a = 0;
    int b = 0;
    int c = 0;
    for (int i = 0; i < 365; i++)
    {
        if (b >= 20)
        {
            c++;
            a = b = 0;
        }

        if (y[i])
            a++;
        
        b += a;
    }

    if (b > 0)
        c++;

    cout << c << '\n';

    return 0;
}