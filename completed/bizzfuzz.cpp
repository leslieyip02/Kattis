#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

ull gcd(ull x, ull y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int main()
{
    ull A, B, C, D;
    cin >> A >> B >> C >> D;
    ull d = C / gcd(C, D) * D;

    ull x = ceil(A / d) * d;
    ull y = (B - x) / d;
    if (A % d == 0)
    {
        y++;
    }
    cout << y << '\n';
    return 0;
}
