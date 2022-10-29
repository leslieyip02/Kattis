#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, n, m, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        
        vector<int> p[n];
        int v[n];
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            
            p[i].resize(k);
            for (int j = 0; j < k; j++)
                cin >> p[i][j];

            cin >> v[i];
        }
        
        int s[m];
        for (int i = 0; i < m; i++)
            cin >> s[i];

        int x = 0;
        for (int i = 0; i < n; i++)
        {
            int y = __INT_MAX__;
            for (int j : p[i])
                y = min(s[j - 1], y);;

            x += y * v[i];
        }

        cout << x << '\n';
    }

    return 0;
}