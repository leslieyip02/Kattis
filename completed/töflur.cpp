#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a + n);
    unsigned long long sum = 0;
    for (int i = 1; i < n; i++)
    {
        long long y = a[i] - a[i - 1];
        sum += y * y;
    }

    cout << sum << '\n';

    return 0;
}