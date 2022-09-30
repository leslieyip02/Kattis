#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, k;
    cin >> n;

    int a[n], b[n];
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    int c[2 * n], d[n];
    for (i = 1; i < n; i++)
    {
        c[i - 1] = c[n + i - 1] = a[i] - a[i - 1];
        d[i - 1] = b[i] - b[i - 1];
    }
    c[n - 1] = c[2 * n - 1] = a[0] - a[n - 1] + 360000;
    d[n - 1] = b[0] - b[n - 1] + 360000;

    // kmp pattern search
    int prefix[n + 1] = { 0 };
    prefix[0] = -1;

    // compute prefix
    for (i = 0, m = -1; i < n; i++)
    {
        while (m >= 0 && d[m] != d[i])
            m = prefix[m];

        prefix[i + 1] = ++m;
    }

    // match
    for (i = 0, m = 0; i < 2 * n; i++)
    {
        while (m >= 0 && d[m] != c[i])
            m = prefix[m];

        if (++m == n)
        {
            cout << "possible\n";
            return 0;
        }
    }

    cout << "impossible\n";
    return 0;
}