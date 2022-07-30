#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int D, V;
double V0;
const double PI = 3.14159265358979323846;

double volume(double d)
{
    // volume of truncated cone = 1 / 3 * π * (r1² + r1 * r2 + r2²) * h
    return V0 - 
        1 / 3.0 * PI * (pow(D / 2.0, 2) + (D / 2.0) * (d / 2) + pow(d / 2, 2)) * (D - d) - 
        PI * pow(d / 2, 2) * d;
}

int main()
{
    cin >> D >> V;
    while (D != 0 && V != 0)
    {
        V0 = PI * pow(D / 2.0, 2) * D;

        double lo = 0;
        double hi = D;
        double d = D / 2;
        double V1 = volume(d);

        while (abs(V - V1) > 0.0000001)
        {
            if (V1 > V)
                lo = d;
            else
                hi = d;

            d = (lo + hi) / 2;
            V1 = volume(d);
        }
        cout << setprecision(10) << d << endl;

        cin >> D >> V;
    }

    return 0;
}