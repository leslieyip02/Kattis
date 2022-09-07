#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int h[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int p = h[0];
    int t = h[0];
    int mjd = 0;
    for (int i = 1; i < n; i++)
    {
        if (h[i] < t)
            t = h[i];

        if (h[i] >= p)
        {
            mjd = max(p - t, mjd);
            p = t = h[i];
        }
        else
        {
            mjd = max(h[i] - t, mjd);
        }
    }

    cout << mjd << '\n';

    return 0;
}