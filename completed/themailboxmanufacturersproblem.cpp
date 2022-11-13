#include <iostream>
using namespace std;

int dp[11][101][101];

int test(int k, int n, int m)
{
    // found, no more crackers needed
    if (n == m)
        return 0;

    // number needed to find up to m
    // is the sum of numbers from 1 to m => m * (m + 1) / 2
    // so number needed to find between n and m
    // is the difference between the 2 sums
    if (k == 1)
        return (m * (m + 1) - n * (n + 1)) / 2;

    // return if found in cache
    if (dp[k][n][m] != 0)
        return dp[k][n][m];
    
    dp[k][n][m] = __INT_MAX__;
    for (int i = n + 1; i <= m; i++)
    {
        // if box explodes, search from lower bound to 
        // 1 less than the tested number
        int boom = i + test(k - 1, n, i - 1);
        // if box survives, search from 1 more than 
        // tested number to upper bound
        int safe = i + test(k, i, m);

        // find optimal way (minimising)
        // to deal with worst case (maximising)
        dp[k][n][m] = min(max(boom, safe), dp[k][n][m]);
    }

    return dp[k][n][m];
}

int main()
{
    int n, k, m;
    cin >> n;
    while (n--)
    {
        cin >> k >> m;
        cout << test(k, 0, m) << '\n';
    }
}