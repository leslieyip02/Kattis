#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

const int B = 1000000000;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    if (y == 0)
        return x;

    return x > y ? gcd(y, x % y) : gcd(x, y % x);
}

ull lcm(int x, int y)
{
    return (x * y) / gcd(x, y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w;
    cin >> n;

    while (n--)
    {
        cin >> w;

        int p[w];
        for (int i = 0; i < w; i++)
            cin >> p[i];

        ull jp = 1;
        for (int i = 0; i < w; i++)
        {
            jp = lcm(p[i], jp);
            if (jp > B)
                break;
        }

        if (jp > B)
            cout << "More than a billion.\n";
        else
            cout << jp << '\n';
    }

    return 0;
}