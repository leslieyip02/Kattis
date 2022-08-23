#include <iostream>
using namespace std;

#define ull unsigned long long

ull factorial(int n)
{
    for (int i = n - 1; i >= 2; i--)
        n *= i;
    return n;
}

ull nCr(int n)
{
    return factorial(n) / (2 * factorial(n - 2));
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m = 0;
    for (int i = 2; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < i; j++)
            if (a[j] > a[i])
                c++;
        cout << c << endl;
        m += nCr(c);
    }

    cout << m << endl;

    return 0;
}