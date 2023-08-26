#include <iostream>
#include <vector>
using namespace std;

#define inf 100000

int n, k;

int diff(string s1, string s2)
{
    int d = 0;
    for (int i = 0; i < k; i++)
    {
        if (s1[i] != s2[i])
        {
            d++;
        }
    }
    return d;
}

int sum(vector<vector<int>>& g, int source)
{
    int d[n];
    bool s[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = inf;
        s[i] = false;
    }

    d[source] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int j;
        int m = inf;
        for (int k = 0; k < n; k++)
        {
            if (!s[k] && d[k] < m)
            {
                j = k;
            }
        }

        s[j] = true;
        for (int k = 0; k < n; k++)
        {
            if (!s[k] && g[j][k] != inf && d[j] != inf && d[j] + g[j][k] < d[k]) {
                d[k] = d[j] + g[j][k];
            }
        }
    }

    for (auto i : d) cout << i << " "; cout << endl;

    int w = 0;
    for (int i : d)
    {
        w += i;
    }
    return w;
}

int main()
{
    cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<vector<int>> g(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            g[i][j] = g[j][i] = diff(s[i], s[j]);
        }
    }

    for (auto i : g) { for (auto j : i) cout << j << ' '; cout << endl; } cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << sum(g, i) << endl;
    }

    return 0;
}
