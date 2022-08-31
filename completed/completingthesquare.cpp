#include <iostream>
#include <math.h>
using namespace std;

struct vect2
{
    int x;
    int y;
};

double dist(vect2 a, vect2 b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    vect2 pts[3];
    for (int i = 0; i < 3; i++)
        cin >> pts[i].x >> pts[i].y;

    double d01 = dist(pts[0], pts[1]);
    double d02 = dist(pts[0], pts[2]);
    double d12 = dist(pts[1], pts[2]);

    // index of opposite corner
    int pi = d01 == d02 ? 0 : d01 == d12 ? 1 : 2;
    
    int x = -pts[pi].x;
    int y = -pts[pi].y;
    for (int i = 0; i < 3; i++)
    {
        if (i == pi)
            continue;

        x += pts[i].x;
        y += pts[i].y;
    }

    cout << x << ' ' << y << '\n';

    return 0;
}