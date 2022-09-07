#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

string b[] = { "qwertyuiop", "asdfghjkl ", "zxcvbnm   " };

pair<int, int> find(char c)
{
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 10; x++)
            if (b[y][x] == c)
                return { x, y };
    return { -1, -1 };
}

int dist(string s, string t)
{
    int v = 0;
    for (int i = 0; i < s.length(); i++)
    {
        pair<int, int> p = find(s[i]);
        pair<int, int> q = find(t[i]);
        
        v += abs(p.first - q.first);
        v += abs(p.second - q.second);
    }
    
    return v;
}

int main()
{
    int t, n;
    string s0;
    
    cin >> t;
    while (t--)
    {
        cin >> s0 >> n;

        pair<string, int> s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i].first;
            s[i].second = dist(s0, s[i].first);
        }

        sort(s, s + n);
        sort(s, s + n, [](const pair<string, int> &a, const pair<string, int> &b)
        {
            return a.second < b.second;
        });
        
        for (pair<string, int> w : s)
            cout << w.first << " " << w.second << '\n';
    }

    return 0;
}