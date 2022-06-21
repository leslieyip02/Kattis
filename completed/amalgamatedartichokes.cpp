#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int p, a, b, c, d;

double price(int k);

int main()
{
    int n;
    cin >> p >> a >> b >> c >> d;
    cin >> n;

    double peak = 0;
    double decline = 0;
    for (int i = 1; i <= n; i++)
    {
        double current = price(i);
        peak = max(peak, current);
        decline = max(decline, peak - current);
    }

    cout << setprecision(10) << decline << endl;

    return 0;
}

double price(int k)
{
    return p * (sin(a * k + b) + cos(c * k + d) + 2);
}