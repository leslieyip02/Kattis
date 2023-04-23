#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, x, y;
        long p;
        double r;
        cin >> n;

        p = 0;
        while (n--)
        {
            cin >> x >> y;
            r = sqrt(x * x + y * y);

            if (r <= 20.0)
            {
                p += 10;
            }
            else if (r <= 40.0)
            {
                p += 9;
            }
            else if (r <= 60.0)
            {
                p += 8;
            }
            else if (r <= 80.0)
            {
                p += 7;
            }
            else if (r <= 100.0)
            {
                p += 6;
            }
            else if (r <= 120.0)
            {
                p += 5;
            }
            else if (r <= 140.0)
            {
                p += 4;
            }
            else if (r <= 160.0)
            {
                p += 3;
            }
            else if (r <= 180.0)
            {
                p += 2;
            }
            else if (r <= 200.0)
            {
                p += 1;
            }
        }

        cout << p << endl;
    }

    return 0;
}
