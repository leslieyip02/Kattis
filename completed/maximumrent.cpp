#include <iostream>
using namespace std;

int main()
{
    // linear progranming
    int a, b, m, o, r, x, y;
    cin >> a >> b >> m >> o;

    // R = ax + by
    // x ≥ 1, y ≥ 1
    // x + y ≤ m
    // 2x + y ≥ σ

    if (a > b)
    {
        // maximise x
        x = m - 1;
        y = 1;
    }
    else
    {
        // maximise y
        x = max(o - m, 1);
        y = m - x;
    }

    r = a * x + b * y;

    cout << r << '\n';
    return 0;
}