#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int A, H, n, m;

int dmg(int a2, int h2)
{
    int h1 = 0;
    h2 -= A;

    while (h2 >= 1)
    {
        h1 += a2;
        h2 -= A;
    }

    return h1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> H >> n >> m;

    int e, b, a, h;
    vector<vector<pair<int, int>>> c(n, vector<pair<int, int>>());
    while (m--)
    {
        cin >> e >> b >> a >> h;
        c[e - 1].push_back({dmg(a, h), b - 1});
    }

    // store distance and node index
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    vector<int> d(n, INT32_MAX);
    d[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto itr : c[node])
        {
            int x = itr.first;
            int y = itr.second;
            if (dist + x < d[y])
            {
                d[y] = dist + x;
                pq.push({d[y], y});
            }
        }
    }

    H -= d[n - 1];
    if (H <= 0)
    {
        cout << "Oh no\n";
    }
    else
    {
        cout << H << endl;
    }

    return 0;
}