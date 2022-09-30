#include <iostream>
using namespace std;

#define ll long long

int main()
{
    ll n, m, i, k;
    bool meow;
    cin >> n;

    for (m = 1 << 7; m > 1; m--)
    {
        meow = true;
        k = n;
        for (i = 0; i < 9; i++)
        {
            if (k % m != 0)
            {
                meow = false;
                break;
            }

            k /= m;
        }

        if (meow)
            break;
    }

    cout << m << '\n';

    return 0;
}