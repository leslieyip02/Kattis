#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> r(m);
    for (int i = 0; i < m; i++)
    {
        cin >> r[i];
    }

    vector<int> p(n);
    for (int i = 1; i <= n; i++)
    {
        int k = i;
        for (int j = 0; j < m; j++)
        {
            if (k == r[j])
            {
                k++;
            }
            else if (k == r[j] + 1)
            {
                k--;
            }
        }
        p[k - 1] = i;
    }

    for (int q : p)
    {
        cout << q << ' ';
    }
    cout << '\n';

    return 0;
}