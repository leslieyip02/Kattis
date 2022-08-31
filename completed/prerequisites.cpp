#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int k, m, c, r, a;
    cin >> k;
    while (k != 0)
    {
        cin >> m;

        int f[k];
        for (int i = 0; i < k; i++)
            cin >> f[i];

        bool qualified = true;
        for (int i = 0; i < m; i++)
        {
            cin >> c >> r;

            for (int j = 0; j < c; j++)
            {
                cin >> a;
                for (int g : f)
                    if (g == a)
                        r--;
            }

            if (r > 0)
                qualified = false;
        }

        cout << (qualified ? "yes\n" : "no\n");

        cin >> k;
    }

    return 0;
}