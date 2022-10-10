#include <bits/stdc++.h>
using namespace std;

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h, w1, w2, m0, mi, t;
    cin >> n >> h;
    
    int halfn = n / 2;

    map<int, int> bottom;
    map<int, int> top;

    for (int i = 0; i < halfn; i++)
    {
        cin >> w1 >> w2;

        if (bottom.find(w1) == bottom.end())
            bottom[w1] = 0;
        bottom[w1]++;

        if (top.find(w2) == top.end())
            top[w2] = 0;
        top[w2]++;
    }

    int a = 0;
    for (auto i = bottom.rbegin(); i != bottom.rend(); i++)
        a = i->second += a;

    a = 0;
    for (auto i = top.rbegin(); i != top.rend(); i++)
        a = i->second += a;

    bottom[0] = top[0] = halfn;
    bottom[h] = top[h] = 0;

    m0 = __INT_MAX__;
    for (int i = 1; i <= h; i++)
    {

        mi = bottom.lower_bound(i)->second + 
            top.lower_bound(h - i + 1)->second;
        
        if (mi < m0)
        {
            m0 = mi;
            t = 0;
        }

        if (mi == m0)
            t++;
    }

    cout << m0 << ' ' << t << '\n';

    return 0;
}
