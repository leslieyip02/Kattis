#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string x;
    map<string, int> l;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        l.insert({x, i});
    }

    vector<bool> y(m, true);
    set<string> z;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            z.insert(x);
        }

        for (auto a : l)
        {
            if (z.find(a.first) == z.end())
            {
                y[a.second] = false;
            }
        }

        z.clear();
    }

    vector<string> ok;
    for (auto a : l)
    {
        if (y[a.second])
        {
            ok.push_back(a.first);
        }
    }

    cout << ok.size() << '\n';
    for (auto a : ok)
    {
        cout << a << '\n';
    }

    return 0;
}