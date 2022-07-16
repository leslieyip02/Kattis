#include <iostream>
#include <iomanip>
#include <cmath>
#include <utility>
using namespace std;

struct point { int x; int y; };

double distance_between(point a, point b, point c)
{
    double dot = (a.x - b.x) * (c.x - b.x) + (a.y - b.y) * (c.y - b.y);
    double len_sq = pow(c.x - b.x, 2) + pow(c.y - b.y, 2);
    double d = dot / len_sq;

    if (len_sq == 0)
        d = -1;

    double x, y;
    if (d < 0)
    {
        x = b.x;
        y = b.y;
    }
    else if (d > 1)
    {
        x = c.x;
        y = c.y;
    }
    else
    {
        x = b.x + d * (c.x - b.x);
        y = b.y + d * (c.y - b.y);
    }

    return sqrt(pow(a.x - x, 2) + pow(a.y - y, 2));
}

int main()
{
    int t, ni, no;
    cin >> t;
    for (int c = 0; c < t; c++)
    {
        cin >> ni;
        point inner[ni];
        for (int i = 0; i < ni; i++)
            cin >> inner[i].x >> inner[i].y;

        cin >> no;
        point outer[no];
        for (int i = 0; i < no; i++)
            cin >> outer[i].x >> outer[i].y;


        double minimumDiameter = 10000;
        int i2 = no - 1;
        for (int i1 = 0; i1 < no; i1++)
        {
            for (int j = 0; j < ni; j++)
            {
                minimumDiameter = min(distance_between(inner[j], outer[i1], outer[i2]), minimumDiameter);
            }
            i2 = i1;
        }

        cout << setprecision(10) << minimumDiameter / 2 << endl;
    }
}
