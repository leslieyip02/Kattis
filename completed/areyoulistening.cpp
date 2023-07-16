#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int cx, cy, n, dx, dy, r;
    cin >> cx >> cy >> n;

    vector<double> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dx >> dy >> r;
        d[i] = max(sqrt(pow(cx - dx, 2) + pow(cy - dy, 2)) - r, 0.0);
    }
    sort(d.begin(), d.end());
    cout << (int) (d[2]) << '\n';
    return 0;
}