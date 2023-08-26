#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, K, i, j, c;
    cin >> N >> M >> K;
    vector<double> p(N);
    vector<double> q(M + K);
    for (i = 0; i < N; i++)
    {
        cin >> p[i];
    }

    for (i = 0; i < M; i++)
    {
        cin >> q[i];
    }
    for (i = 0; i < K; i++)
    {
        cin >> q[i + M];
        q[i + M] = sqrt(2 * pow(q[i + M], 2)) / 2;
    }

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    c = 0;
    i = 0;
    j = 0;
    while (i < N && j < M + K)
    {
        if (q[j] < p[i])
        {
            c++;
            j++;
        }
        i++;
    }
    cout << c << '\n';

    return 0;
}