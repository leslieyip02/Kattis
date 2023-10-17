#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a, b;
    cin >> a >> b;

    int p, q;
    vector<vector<int>> tunnels(n, vector<int>(n, INF));
    while (m--)
    {
        cin >> p >> q;
        tunnels[p][q] = 1;
        tunnels[q][p] = 1;
    }

    // djikstra
    vector<bool> visited(tunnels.size(), false);
    vector<int> distance(tunnels.size(), INF);
    distance[a] = 0;
    for (int i = 0; i < tunnels.size(); i++)
    {
        int from;
        int closest = INF;
        for (int j = 0; j < tunnels.size(); j++)
        {
            if (!visited[j] && distance[j] <= closest)
            {
                from = j;
                closest = distance[j];
            }
        }

        if (from == b)
        {
            break;
        }

        visited[from] = true;
        for (int j = 0; j < tunnels.size(); j++)
        {
            if (!visited[j])
            {
                distance[j] = min(distance[from] + tunnels[from][j], distance[j]);
            }
        }
    }

    int t = (int) ceil(distance[b] / 2.0);
    cout << t << '\n';

    return 0;
}