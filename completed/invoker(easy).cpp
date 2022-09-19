#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    long a, b, c, d;

    cin >> a >> b >> c >> d;

    double r = (double) c / (c * c + d * d);
    double i = c == 0 ? -1.0 / d : -d * r / c;

    double x = a * r - b * i;
    double y = b * r + a * i;

    cout << setprecision(6) << x << ' ' << y << '\n';

    return 0;
}