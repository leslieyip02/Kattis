#include <iostream>
using namespace std;

#define ull unsigned long long

ull gcd(ull x, ull y)
{
    if (x == 0)
    {
        return y;
    }

    if (y == 0)
    {
        return x;
    }

    return x > y ? gcd(y, x % y) : gcd(x, y % x);
}

int main()
{
    ull M, N;
    cin >> M >> N;

    ull x = gcd(M, N);

    M /= x;
    N /= x;

    cout << (N % 2 + M % 2 == 2 ? x : 0) << '\n';

    return 0;
}