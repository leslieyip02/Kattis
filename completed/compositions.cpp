#include <iostream>
#include <map>
using namespace std;

typedef unsigned long long ull;

int P, K, n, m, k;
map<int, ull> memo;

ull choose(int t)
{
    if (t == 0)
    {
        return 1;
    }
    if (memo.find(t) != memo.end())
    {
        return memo[t];
    }

    ull w = 0;
    for (int i = 1; i <= t; i++) {
        if (i < m || (i - m) % k != 0) {
            w += choose(t - i);
        }
    }
    memo[t] = w;
    return w;
}

int main()
{
    cin >> P;
    while (P--)
    {
        memo.clear();
        cin >> K >> n >> m >> k;
        cout << K << ' ' << choose(n) << '\n';
    }

    return 0;
}
