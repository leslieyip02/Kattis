#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }

    int p = 2147483647;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int q = 0;
            for (int s = 0; s < n; s++)
            {
                for (int t = 0; t < m; t++)
                {
                    q += g[s][t] * (abs(s - i) + abs(t - j));
                }
            }

            p = min(p, q);
        }
    }

    cout << p << '\n';

    return 0;
}