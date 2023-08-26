#include <iostream>
using namespace std;

#define ull unsigned long long
#define M (ull) (1e9 + 7)

int pow(ull a, ull b)
{
    ull p = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            p = (p * a) % M;
        }
        b >>= 1;
        a = (a * a) % M;
    }
    return (int) p;
}

int main()
{
    int L, R;
    cin >> L >> R;

    ull n = 0;
    for (ull i = L; i <= R; i++)
    {
        n = (n + pow(5, (i + 1) / 2)) % M;
        n = (n + pow(2, (i + 1) / 2)) % M;
    }
    cout << n << '\n';

    return 0;
}
