#include <iostream>
#include <iomanip>
#include <utility>
#include <cstring>
using namespace std;

double win(int a, int b)
{
    return (double) a / (a + b);
}

double champion(pair<int, int> b1, pair<int, int> b2)
{
    // probabilities of making it through round 1
    double r1a = win(b1.first, b1.second);
    double r1b = win(b2.first, b2.second);

    // probabilities for round 2
    double r2a = win(b1.first, b2.first);
    double r2b = win(b1.first, b2.second);

    return r1a * (r1b * r2a + (1.0 - r1b) * r2b);
}

int main()
{
    int k, t, p, q, x;
    cin >> k >> t >> p >> q >> x;

    p %= q;

    // dp[number of guesses][number of correct guesses]
    double dp[t + 1][t + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1.0;

    for (int i = 0; i < t; i++)
    {
        int w[4];
        for (int j = 0; j < 4; j++)
            cin >> w[j];

        // assign 2 brackets for the tournament
        pair<int, int> b1, b2;
        int m = x % 4;

        if (m < 2)
        {
            b1 = { w[0], w[1] };
            b2 = { w[2], w[3] };
        }
        else
        {
            b1 = { w[2], w[3] };
            b2 = { w[0], w[1] };
        }

        if (m % 2 == 1)
            swap(b1.first, b1.second);

        double pw = champion(b1, b2);
        for (int j = 0; j < t; j++)
        {
            // correct guess
            dp[i + 1][j + 1] += dp[i][j] * pw;
            // wrong guess
            dp[i + 1][j] += dp[i][j] * (1.0 - pw);
        }

        x = (x * p) % q;
    }

    double res = 0;
    for (int i = k; i <= t; i++)
        res += dp[t][i];
    cout << setprecision(10) << res << '\n';

    return 0;
}