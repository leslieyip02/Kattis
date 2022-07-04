#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

int main()
{
    double x, y, r;
    int t = 1;
    while (cin >> x)
    {
        cin >> y >> r;

        double xn = x;
        double yn = y;
        
        while (r > 0 && sqrt(pow(xn, 2) + pow(yn, 2)) < 2)
        {
            double xi = xn;
            xn = pow(xn, 2) - pow(yn, 2) + x;
            yn = 2 * xi * yn + y;
            r--;
        }

        cout << "Case " << t << ": ";
        cout << (r == 0 ? "IN" : "OUT") << endl;
        t++;
    }

    return 0;
}