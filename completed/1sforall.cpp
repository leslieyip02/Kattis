#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int dp[100001];
    fill_n(dp, 100001, 100000);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        // check for addition
        for (int j = 1; j < i; j++)
        {
            dp[i] = min(dp[j] + dp[i - j], dp[i]);
        }

        // check for multiplication
        for (int j = 2; j <= (int) sqrt(i); j++)
        {
            if (i % j == 0)
            {
                dp[i] = min(dp[j] + dp[i / j], dp[i]);
            }
        }

        // check for concatenation
        if (i >= 10)
        {
            string s = to_string(i);
            for (int j = 1; j < s.length(); j++)
            {
                // continue if leading 0
                if (s[j] == '0')
                {
                    continue;
                }

                int left = stoi(s.substr(0, j));
                int right = stoi(s.substr(j, s.length() - j));
                dp[i] = min(dp[left] + dp[right], dp[i]);
            }
        }
    }

    cout << dp[n] << '\n';

    return 0;
}