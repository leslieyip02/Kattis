#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int d, x, y, h;
    cin >> d >> x >> y >> h;

    double xx = x * x;
    double n = 0.5 * h;
    
    double a = sqrt(xx + y * y);
    double b = sqrt(xx + pow(y + n, 2));
    double c = sqrt(xx + pow(y - n, 2));
    double r = d * (tan(asin(n * x / a / b)) + tan(asin(n * x / a / c)));

    cout << setprecision(8) << r << '\n';

    return 0;
}