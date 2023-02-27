#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, c;
    cin >> n;

    vector<vector<int>> r;
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            cin >> c;
            if (c != -1)
            {
                r.push_back({ u, v, c });
            }
        }
    }

    cout << r.size() << '\n';
    for (auto t : r)
    {
        cout << t[0] << ' ' << t[1] << ' ' << t[2] << '\n';
    }

    return 0;
}