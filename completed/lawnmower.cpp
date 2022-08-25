#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int nx, ny;
    double w;
    cin >> nx >> ny >> w;

    while (nx != 0 && ny != 0 && w != 0)
    {
        bool across;
        double l[nx];
        for (int i = 0; i < nx; i++)
            cin >> l[i];

        bool along;
        double h[ny];
        for (int i = 0; i < ny; i++)
            cin >> h[i];

        sort(l, l + nx);
        across = l[0] <= w / 2 && l[nx - 1] >= 75 - w / 2;
        for (int i = 0; i < nx - 1; i++)
        {
            if (l[i + 1] - l[i] > w)
                across = false;

            if (!across)
                goto next;
        }

        sort(h, h + ny);
        along = h[0] <= w / 2 && h[ny - 1] >= 100 - w / 2;
        for (int i = 0; i < ny - 1; i++)
        {
            if (h[i + 1] - h[i] > w)
                along = false;

            if (!along)
                break;
        }

        next:
            cout << (across && along ? "YES\n" : "NO\n");

        cin >> nx >> ny >> w;
    }

    return 0;
}