#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

char c[] = { '-', '%', 'X', 'x', '.', 'o', 'O', '0', '+' };

const double PI = 3.14159265358979323846;
const double t1 = 1 / PI;
const double t2 = t1 / PI;
const double t3 = t2 / PI;

char potential(double v)
{
    int i = 4;
    
    if (abs(v) == INFINITY)
        i += v > 0 ? 4 : -4;
    else if (abs(v) >= t1)
        i += v > 0 ? 3 : -3;
    else if (abs(v) >= t2)
        i += v > 0 ? 2 : -2;
    else if (abs(v) >= t3)
        i += v > 0 ? 1 : -1;

    return c[i];
}

int main()
{
    int n, m, q, x, y;
    char s;
    
    cin >> n >> m >> q;
    double g[n][m];
    memset(g, 0, n * m * sizeof(double));

    while (q--)
    {
        cin >> x >> y >> s;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                g[i - 1][j - 1] += (s == '+' ? 1 : -1) / sqrt(pow(j - x, 2) + pow(i - y, 2));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m ; j++)
            cout << potential(g[i][j]);
        cout << '\n';
    }

    return 0;
}
