#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m;

    vector<int> p(n);
    map<int, int> t;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> x;
        t[x] = 0;
    }

    for (auto i : p)
    {
        auto itr1 = t.lower_bound(i);
        if (itr1 == t.end())
        {
            itr1--;
        }
        auto itr2 = itr1;
        if (itr2 != t.begin())
        {
            itr2--;
        }

        auto found = (itr1->first - i) < (i - itr2->first) ? itr1 : itr2;
        found->second++;
    }

    y = 0;
    for (auto h : t)
    {
        if (h.second)
        {
            y++;
        }
    }

    cout << n - y << '\n';
    return 0;
}