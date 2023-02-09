#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int closest_sum(vector<int> y, int n, int q)
{
    if (*y.begin() >= q)
        return *y.begin();

    if (*y.rbegin() <= q)
        return *y.rbegin();

    int hi = n;
    int lo = 0;
    int mid;

    while (hi > lo)
    {
        mid = (hi + lo) / 2;

        if (y[mid] == q)
            return q;

        if (y[mid] > q)
        {
            if (mid > 0 && q > y[mid - 1])
                return abs(y[mid - 1] - q) < abs(y[mid] - q) ? 
                    y[mid - 1] : y[mid];

            hi = mid;
        }
        else
        {
            if (mid < n - 1 && q < y[mid + 1])
                return abs(y[mid + 1] - q) < abs(y[mid] - q) ? 
                    y[mid + 1] : y[mid];

            lo = mid;
        }
    }

    return y[mid];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    int c = 1;
    vector<int> x, y;

    while (cin >> n)
    {
        x.resize(n);
        y.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];

            for (int j = 0; j < i; j++)
                y.push_back(x[i] + x[j]);
        }
        sort(y.begin(), y.end());

        cout << "Case " << c++ << ":\n";
        cin >> m;
        while (m--)
        {
            cin >> q;
            cout << "Closest sum to " << q
                << " is " << closest_sum(y, y.size(), q) << ".\n";
        }
    }

    return 0;
}