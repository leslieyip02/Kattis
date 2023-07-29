#include <iostream>
using namespace std;

#define ull unsigned long long

int main()
{
    int V, W;
    cin >> V;

    ull s = 6 * 1e6 * 1e6;
    for (int i = 1; i * i <= V; i++)
    {
        if (V % i != 0)
        {
            continue;
        }
        W = V / i;
        for (int j = 1; j * j <= W; j++)
        {
            if (W % j != 0)
            {
                continue;
            }
            int k = W / j;
            ull t = 2 * (i * j + i * k + j * k);
            s = min(s, t);
        }
    }

    cout << s << '\n';
    return 0;
}