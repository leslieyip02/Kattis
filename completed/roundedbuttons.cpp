#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, m;
    double x, y, w, h, r, a, b;
    cin >> n;
    while (n--)
    {
        cin >> x >> y >> w >> h >> r >> m;
        while (m--)
        {
            cin >> a >> b;
            bool ok = true;
            if (a < x || a > x + w || b < y || b > y + h)
            {
                ok = false;
            }
            else
            {
                bool i = abs(a - x) < r;
                bool j = abs(x + w - a) < r;
                bool k = abs(b - y) < r;
                bool l = abs(y + h - b) < r;
                if (i + j + k + l == 2)
                {
                    double cx = i ? x + r : x + w - r;
                    double cy = k ? y + r : y + h - r;
                    ok = sqrt(pow(cx - a, 2) + pow(cy - b, 2)) <= r;
                }
            }
            cout << (ok ? "in" : "out") << "side\n";
        }
        cout << '\n';
    }
    return 0;
}
