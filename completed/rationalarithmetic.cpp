#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    ll x1, y1, x2, y2, d, numerator, denominator;
    char op;
    while (t--)
    {
        cin >> x1 >> y1 >> op >> x2 >> y2;

        if (op == '+')
        {
            numerator = x1 * y2 + x2 * y1;
            denominator = y1 * y2;
        }

        if (op == '-')
        {
            numerator = x1 * y2 - x2 * y1;
            denominator = y1 * y2;
        }

        if (op == '*')
        {
            numerator = x1 * x2;
            denominator = y1 * y2;
        }

        if (op == '/')
        {
            numerator = x1 * y2;
            denominator = y1 * x2;
        }

        d = __gcd(numerator, denominator);
        numerator /= d;
        denominator /= d;

        if (denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }

        cout << numerator << " / " << denominator << '\n';
    }

    return 0;
}