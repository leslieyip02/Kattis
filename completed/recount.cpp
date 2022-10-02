#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string c;
    getline(cin, c);
    map<string, int> v;

    int t = 1;
    while (c != "***")
    {
        if (v.find(c) == v.end())
            v.insert({ c, 0 });
        v[c]++;
        t++;
        getline(cin, c);
    }

    auto w = max_element(v.begin(), v.end(),
        [](const auto &a, const auto &b)
        {
            return a.second < b.second;
        });

    int x = 0;
    for (auto p : v)
        if (p.second == w->second)
            x++;

    cout << ((double) w->second / t > 0.5 || x == 1 ? w->first : "Runoff!") << '\n';

    return 0;
}