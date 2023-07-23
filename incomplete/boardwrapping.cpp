#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

struct Point
{
    double x;
    double y;
};

Point rotate_point(Point p, Point pivot, double s, double c)
{
    Point rotated;
    rotated.x = c * (p.x - pivot.x) - s * (p.y - pivot.y) + pivot.x;
    rotated.y = s * (p.x - pivot.x) + c * (p.y - pivot.y) + pivot.y;
    return rotated;
}

int counter_clockwise(Point a, Point b, Point c)
{
    return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y) < 0; 
}

int main()
{
    int N, n, index, left, next;
    double x, y, w, h, v, r, s, c;
    double boards, total;
    vector<int> indices;
    vector<Point> p;
    Point centre;

    cin >> N;
    while (N--)
    {
        boards = total = 0.0;
        left = 0;

        cin >> n;
        p.resize(n * 4);
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y >> w >> h >> v;
            centre.x = x;
            centre.y = y;
            boards += w * h;
            r = v / 180 * PI;

            s = sin(r);
            c = cos(r);

            // get the 4 corners and then rotate about centre
            double corners[4][2] = {{ 1, 1 }, { -1, 1 }, { 1, -1 }, { -1, -1 }};
            for (int j = 0; j < 4; j++)
            {
                index = i * 4 + j;
                p[index].x = x + corners[j][0] * 0.5 * w;
                p[index].y = y + corners[j][1] * 0.5 * h;
                p[index] = rotate_point(p[index], centre, s, c);

                if (p[index].x < p[left].x)
                {
                    left = index;
                }
            }
        }
        
        // jarvis algorithm
        indices.clear();
        index = left;
        do
        {
            indices.push_back(index);

            // pick next point
            next = (index + 1) % p.size();
            for (int i = 0; i < p.size( ); i++)
            {
                if (counter_clockwise(p[index], p[i], p[next]))
                {
                    next = i;
                }
            }

            index = next;
        }
        while (index != left);

        // shoelace method
        for (int i = 0; i <= indices.size(); i++)
        {   
            index = indices[i];
            next = indices[(i + 1) % indices.size()];
            total += p[index].x * p[next].y - p[next].x * p[index].y;
        }

        total *= 0.5;
        cout << (boards / total) * 100 << '\n';
    }

    return 0;
}