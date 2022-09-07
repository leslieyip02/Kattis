#include <iostream>
using namespace std;

#define U 100
#define M 1001113
int PDC[U + 1][U] = { 0 };

int descend(int n, int v)
{
    if (!PDC[n][v])
        PDC[n][v] = ((v + 1) * descend(n - 1, v) + (n - v) * descend(n - 1, v - 1)) % M;
    return PDC[n][v];
}

int main()
{
    for (int i = 0; i <= U; i++)
        PDC[i][0] = PDC[i][i - 1] = 1;

    int p, k, n, v;
    cin >> p;
    while (p--)
    {
        cin >> k >> n >> v;
        
        if (!PDC[n][v])
            PDC[n][v] = descend(n, v);
        cout << k << ' ' << PDC[n][v] << '\n';
    }

    return 0;
}