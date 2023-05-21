#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> P(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> P[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            int a = -1;
            int b = -1;

            if (i > 0)
            {
                a = P[i - 1][j];
            }

            if (j > 0)
            {
                b = P[i][j - 1];
            }

            P[i][j] += max(a, b);
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << P[i][M - 1] << ' ';
    }
    cout << '\n';

    return 0;
}