#include <bits/stdc++.h>
using namespace std;

const int B = 1000000000;
bool cds[B];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cd, x;
    cin >> n >> m;

    while (n != 0 || m != 0)
    {
        memset(cds, false, B * sizeof(bool));
        for (int i = 0; i < n; i++)
        {
            cin >> cd;
            cds[cd] = true;
        }
        
        x = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> cd;
            if (cds[cd])
                x++;
        }
        
        cout << x << '\n';
        cin >> n >> m;
    }

    return 0;
}