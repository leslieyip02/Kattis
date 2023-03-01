#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N, A, B, X, T;

    cin >> N;
    vector<vector<double>> nodes;
    nodes.resize(N);
    for (int i = 0; i < N; i++)
    {
        nodes[i] = vector<double>(N, 0.0);
    }

    for (int i = 0; i < N - 1; i++)
    {
        cin >> A >> B >> X >> T;
        // magic pipes are negative because magic
        nodes[B - 1][A - 1] = X / 100.0 * (T == 1 ? -1 : 1);
    }

    double amt, lvl, req = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> amt;
        if (amt <= 0)
        {
            continue;
        }

        lvl = i;
        while (lvl != 0)
        {
            for (int j = 0; j < N; j++)
            {
                if (nodes[lvl][j] != 0)
                {
                    if (nodes[lvl][j] < 0)
                    {
                        amt = sqrt(amt) / -nodes[lvl][j];
                    }
                    else
                    {
                        amt /= nodes[lvl][j];
                    }

                    lvl = j;
                    break;
                }
            }
        }

        req = max(amt, req);
    }

    cout << setprecision(16) << req << endl;

    return 0;
}