#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b;
vector<vector<bool>> islands;
vector<bool> visited;

void bridge(int i)
{
    visited[i] = true;
    for (int j = 0; j < n; j++)
        if (islands[i][j] && !visited[j])
            bridge(j);
}

int main()
{
    cin >> n >> m;

    if (m < n - 1)
    {
        cout << "NO\n";
        return 0;
    }

    islands.resize(n, vector<bool>(n));
    visited.resize(n, false);

    while (m--)
    {
        cin >> a >> b;
        a--; b--;

        islands[a][b] = true;
        islands[b][a] = true;
    }

    bridge(0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}