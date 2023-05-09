#include <iostream>
#include <cmath>
using namespace std;

int c[10001];

int w(int n)
{
    if (c[n])
    {
        return c[n];
    }

    int x = (w(n - 1) + w(n - 2)) % 1000000007;
    c[n] = x;
    return x;
}

int main()
{
    int t, n;
    cin >> t;

    c[1] = 2;
    c[2] = 3;

    while (t--)
    {
        cin >> n;
        cout << w(n) << '\n';
    }

    return 0;
}