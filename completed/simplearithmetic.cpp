#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a, b, c, ab;
    cin >> a >> b >> c;
    
    ab = a * b;
    if (ab >= 10 * c)
    {
        cout << ab / c / 10;
        ab %= 10 * c;
    }
    
    cout << setprecision(18) << fixed << (long double) ab / c << '\n';

    return 0;
}