#include <bits/stdc++.h>
using namespace std;

const int M = 4711;
int dp[M + 1];

int explode(int x0)
{
    // return memoised results
    if (dp[x0] != -1)
        return dp[x0];

    // try to test with a current of xᵢ mA
    // • kaboom! -> test currents from 1 to xᵢ one by one (since no batteries to spare)
    // • safe    -> test currents from xᵢ to x₀ (can blow up 1 battery)
    // get max for number of test needed for worst case
    // get min of tests needed for worst case
    
    int a = INT_MAX;
    for (int xi = 2; xi <= x0; xi++)
        a = min(max(xi - 1, explode(x0 - xi)), a);

    // memoise
    dp[x0] = a + 1;
    return dp[x0];
}

int main()
{
    memset(dp, -1, (M + 1) * sizeof(int));

    dp[0] = dp[1] = 0; // don't need to test for 0 or 1 mA
    dp[2] = 1; // only 1 test needed for 2 mA

    int n;
    cin >> n;

    while (n != 0)
    {
        cout << explode(n) << endl;
        cin >> n;
    }

    return 0;
}