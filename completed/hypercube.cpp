#include <iostream>
#include <string>
using namespace std;

#define ull unsigned long long

ull gray_to_ull(ull n)
{
    ull mask = n;
    while (mask)
    {
        mask >>= 1;
        n ^= mask;
    }
    return n;
}

int main()
{
    int n;
    string a, b;
    cin >> n >> a >> b;

    ull x = stoull(a, nullptr, 2);
    ull y = stoull(b, nullptr, 2);

    cout << gray_to_ull(y) - gray_to_ull(x) - 1 << '\n';

    return 0;
}