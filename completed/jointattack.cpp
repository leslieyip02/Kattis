#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> x;

int main()
{
    int n;
    cin >> n;

    x.resize(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    long numerator = 1;
    long denominator = x.back();
    for (int i = n - 2; i >= 0; i--)
    {
        numerator += x[i] * denominator;
        long d = __gcd(numerator, denominator);
        numerator /= d;
        denominator /= d;

        if (i != 0)
            swap(numerator, denominator);
    }

    cout << numerator << '/' << denominator << '\n';

    return 0;
}