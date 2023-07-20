#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define pii pair<int, int> 

int main()
{
    int n;
    cin >> n;

    vector<pii> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].first;
        s[i].second = i + 1;
    }

    sort(s.begin(), s.end(),
        [](const pii &p1, const pii &p2)
    {
        return p1.first > p2.first;
    });
    s.push_back(s.front());

    bool ok = true;
    for (int i = 1; i < n; i++)
    {
        int x = 0;
        for (int j = 0; j < i; j++)
        {
            int y = min(s[i].first - x, s[j].first);
            s[j].first -= y;
            x += y;
        }
        if (x < s[i].first)
        {
            ok = false;
            break;
        }
    }

    int k = 0;
    for (int i = 1; i < n; i++)
    {
        k += s[i].first;
    }

    ok &= (k == s.back().first);

    if (ok)
    {
        for (int i = 0; i < n; i++)
        {
            cout << s[i].second << ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << "impossible\n";
    }

    return 0;
}