#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n;

    vector<int> a;
    long long s = 0;
    for (int i = 2; i <= n; i++)
    {
        cin >> c;

        if (c != 0)
            a.push_back(c);
        else
            i--;

        s += c * i;
    }

    long long m = s;
    for (int i = 1; i < n; i++)
    {
        s -= a[i - 1] * (i + 1);
        s += a[i - 1] * i;
        m = max(s, m);
    }

    cout << m << '\n';

    return 0;
}