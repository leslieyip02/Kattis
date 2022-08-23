#include <iostream>
using namespace std;

struct point
{
    int x;
    int y;
};

int main()
{
    int n, m;
    cin >> n;
    while (n--)
    {
        cin >> m;
        point pts[m + 1];
        for (int i = 0; i < m; i++)
            cin >> pts[i].x >> pts[i].y;
        pts[m] = pts[0];

        double a = 0;
        for (int i = 0; i < m; i++)
            a += pts[i].y * pts[i + 1].x - pts[i].x * pts[i + 1].y;
            
        cout << (a > 0 ? a / 2 : -a / 2) << endl;
    }

    return 0;
}