#include <iostream>
using namespace std;

int nCr(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }

    int x = n;
    for (int i = r + 1; i < n; i++)
    {
        x *= i;
    }

    int y = n - r;
    for (int i = 2; i < n - r; i++)
    {
        y *= i;
    }

    return x / y;
}

int z(int n)
{
    if (n == 1)
    {
        return 1;
    }

    int x = 0;
    for (int i = 1; i <= n; i++)
    {

        int y = nCr(n, i);
        for (int j = 2; j <= i; j++)
        {
            y *= j;
        }

        x += y;
        if (x > 1e9)
        {
            return -1;
        }
    }

    return x;
}

int main()
{
    int n;
    cin >> n;

    if (n >= 20)
    {
        cout << "JUST RUN!!\n";
        return 0;
    }

    int x = z(n);
    if (x == -1)
    {
        cout << "JUST RUN!!\n";
    }
    else
    {
        cout << x << '\n';
    }

    return 0;
}