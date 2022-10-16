#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t, ci, ti;
    cin >> n >> t;

    priority_queue<int> q[t];
    for (int i = 0; i < t; i++)
        q[i] = priority_queue<int>(1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> ci >> ti;
        q[ti].push(ci);
    }

    int m = 0;
    for (int i = t - 1; i >= 0; i--)
    {
        int k = i;
        for (int j = i + 1; j < t; j++)
            if (q[j].top() > q[k].top())
                k = j;

        m += q[k].top();
        q[k].pop();
    }

    cout << m << '\n';

    return 0;
}