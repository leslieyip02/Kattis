#include <bits/stdc++.h>
using namespace std;

double dist(pair<double, double> a, pair<double, double> b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int n;
    cin >> n;

    pair<double, double> pts[n + 2];
    pts[0] = { x1, y1 };
    pts[n + 1] = { x2, y2 };
    for (int i = 1; i <= n; i++)
        cin >> pts[i].first >> pts[i].second;

    // adjacency matrix
    double adjm[n + 2][n + 2];
    adjm[0][0] = 0;
    for (int i = 1; i < n + 2; i++)
        adjm[0][i] = dist(pts[0], pts[i]) / 5;

    for (int i = 1; i < n + 2; i++)
        for (int j = 0; j < n + 2; j++)
            adjm[i][j] = i == j ? 0 : DBL_MAX;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = i + 1; j < n + 2; j++)
        {
            double d = dist(pts[i], pts[j]);
            adjm[i][j] = adjm[j][i] = min(d / 5, abs(d - 50) / 5 + 2);
        }
    }

    // dijkstra's algorithm
    bool visited[n + 2] = { false };
    visited[0] = true;
    bool done = false;
    while (!done)
    {
        double v = DBL_MAX;
        int vi;

        for (int i = 1; i < n + 2; i++)
        {
            if (!visited[i] && adjm[0][i] < v)
            {
                v = adjm[0][i];
                vi = i;
            }
        }

        for (int i = 1; i < n + 2; i++)
        {
            if (i == vi)
                continue;

            adjm[0][i] = min(adjm[0][vi] + adjm[vi][i], adjm[0][i]);
        }

        visited[vi] = true;
        done = true;
        for (bool node : visited)
        {
            if (!node)
            {
                done = false;
                break;
            }
        }
    }

    cout << adjm[0][n + 1] << endl;

    return 0;
}