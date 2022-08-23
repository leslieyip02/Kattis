#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, m;
    double x, y, a0, a1, d;
    const double PI = 3.14159265358979323846;

    cin >> n;
    while (n--)
    {
        x = 0;
        y = 0;
        a0 = 0;
        cin >> m;
        while (m--)
        {
            cin >> a1 >> d;
            a0 -= a1 / 180 * PI;
            
            x += d * sin(a0);
            y += d * cos(a0);
        }
        cout << x << " " << y << endl;
    }

    return 0;
}