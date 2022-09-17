#include <iostream>
#include <math.h>
using namespace std;

struct hatch
{
    int x;
    int y;
};

double distance(int x, int y, hatch a)
{
    return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
}

int main()
{
    int n, s, h;
    cin >> n;
    while (n--)
    {
        cin >> s >> h;

        hatch c[h];
        for (int i = 0; i < h; i++)
            cin >> c[i].x >> c[i].y;

        for (int x = 1; x < s; x++)
        {
            for (int y = 1; y < s; y++)
            {

                bool valid = true;
                int m = min(x, min(y, min(s - x, s - y)));
                
                for (hatch a : c)
                {
                    if ((x == a.x && y == a.y) ||
                        distance(x, y, a) > m)
                    {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                {
                    cout << x << ' ' << y << '\n';
                    goto next;
                }
            }
        }

        cout << "poodle\n";

        next:
            continue;
    }

    return 0;
}