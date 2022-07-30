#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() 
{
    double x1, y1, x2, y2, p, dx, dy;
    cin >> x1;
    while (x1 != 0)
    {
        cin >> y1 >> x2 >> y2 >> p;
        dx = abs(x1 - x2);
        dy = abs(y1 - y2);
        cout << setprecision(10) <<
            pow(pow(dx, p) + pow(dy, p), 1 / p) << endl;
        
        cin >> x1;
    }

    return 0;
}