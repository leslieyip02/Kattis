#include <iostream>
#include <iomanip>
using namespace std;

int t, x, y;

double vol(double h) 
{
    return (x - 2 * h) * (y - 2 * h) * h;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        double lo = 0;
        double hi = (x < y ? x : y) / 2.0;
        
        while (hi - lo > 0.0000001)
        {
            double h1 = (hi - lo) * (1.0 / 3) + lo;
            double h2 = (hi - lo) * (2.0 / 3) + lo;
            double v1 = vol(h1);
            double v2 = vol(h2);

            if (v1 > v2)
                hi = h2;
            else
                lo = h1;
        }

        cout << fixed << setprecision(10) << vol(lo) << endl;
    }

    return 0;
}