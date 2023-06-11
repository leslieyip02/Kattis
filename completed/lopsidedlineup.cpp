#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n;

    vector<long long> s(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            s[i] += c;
        }
    }

    long long d = 0;
    sort(s.begin(), s.end());

    for (int i = 0; i < n / 2; i++)
    {
        d -= s[i];
    }

    for (int i = n / 2; i < n; i++)
    {
        d += s[i];
    }

    cout << d / 2 << '\n';
    return 0;
}