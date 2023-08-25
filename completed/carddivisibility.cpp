#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main()
{
    ull L, R;
    cin >> L >> R;

    if (R - L > 9)
    {
        R -= (R - L) / 9 * 9;
    }

    int r = 0;
    for (; L <= R; L++)
    {
        r = (r + L % 9) % 9;
    }
    cout << r << '\n';
    return 0;
}
