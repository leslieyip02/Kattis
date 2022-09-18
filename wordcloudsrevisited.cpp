#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c, w, h, best;
    cin >> n >> c;

    pair<int, int> bb[n];
    for (int i = 0; i < n; i++)
        cin >> bb[i].first >> bb[i].second;

    int dp[n + 1] = { 0 };
    
    // try to start a row from each bounding box
    for (int i = n - 1; i >= 0; i--)
    {
        w = 0;
        h = 0;
        best = INT_MAX;

        for (int j = i; j < n; j++)
        {
            w += bb[j].first;
            if (w > c)
                break;

            h = max(bb[j].second, h);
            best = min(h + dp[j + 1], best);
        }

        dp[i] = best;
    }
    
    cout << dp[0] << '\n';

    return 0;
}