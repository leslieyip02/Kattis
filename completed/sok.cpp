#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    double i, j, k, ri, rj, rk, rmin;
    cin >> a >> b >> c;
    cin >> i >> j >> k;

    ri = i / a;
    rj = j / b;
    rk = k / c;
    rmin = max(ri, max(rj, rk));

    cout << fixed << setprecision(6)
        << abs(a - i / rmin) << " "
        << abs(b - j / rmin) << " "
        << abs(c - k / rmin) << endl;   

    return 0;
}