#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int g[50][50];

int main()
{
    int n, m, x, y, i, j;
    cin >> n >> m;

    vector<int> s;
    map<int, set<int>> nw;
    map<int, set<int>> se;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> x;
            if (x == -1)
            {
                continue;
            }
            s.push_back(x);

            y = i + j;
            if (nw.find(y) == nw.end())
            {
                nw[y] = set<int>();
            }
            nw[y].insert(x);

            y = i + (m - j - 1);
            if (se.find(y) == se.end())
            {
                se[y] = set<int>();
            }
            se[y].insert(x);
        }
    }
    sort(s.begin(), s.end());

    int N = 0;
    int W = 0;
    i = 0;
    for (auto d : nw)
    {
        for (j = 0; j < d.second.size(); j++)
        {
            if (d.second.find(s[i + j]) == d.second.end())
            {
                N++;
            }

            if (d.second.find(s[s.size() - 1 - (i + j)]) == d.second.end())
            {
                W++;
            }
        }
        i += d.second.size();
    }

    int S = 0;
    int E = 0;
    i = 0;
    for (auto d : se)
    {
        for (j = 0; j < d.second.size(); j++)
        {
            if (d.second.find(s[i + j]) == d.second.end())
            {
                S++;
            }

            if (d.second.find(s[s.size() - 1 - (i + j)]) == d.second.end())
            {
                E++;
            }
        }
        i += d.second.size();
    }

    cout << min(N, min(E, min(S, W))) << '\n';
    return 0;
}
