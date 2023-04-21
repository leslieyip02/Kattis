#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    double q;
    cin >> n >> q;

    double p, s, m;
    double shares = 0.0;
    double money = 100.0;

    while (n--)
    {
        cin >> p;

        s = max((money - q) / p, shares);
        m = max(shares * p - q, money);

        shares = s;
        money = m;
    }

    cout << setprecision(10) << money << '\n';

    return 0;
}