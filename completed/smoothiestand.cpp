#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, r;
    cin >> k >> r;

    vector<int> q(k);
    for (int i = 0; i < k; i++)
    {
        cin >> q[i];
    }

    int t = 0;
    int a, b, c;
    while (r--)
    {
        b = 1000000;
        for (int i = 0; i < k; i++)
        {
            cin >> a;
            if (a == 0)
            {
                continue;
            }

            b = min(q[i] / a, b);
        }

        cin >> c;
        t = max(b * c, t);
    }

    cout << t << '\n';

    return 0;
}