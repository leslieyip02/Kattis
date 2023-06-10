#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int main()
{
    double d, x, y;
    int N;

    while (cin >> d)
    {
        cin >> N;
        if (d == 0.0 && N == 0)
        {
            break;
        }

        vector<pair<double, double>> h;
        for (int i = 0; i < N; i++)
        {
            cin >> x >> y;
            h.push_back(make_pair(x, y));
        }

        vector<bool> ok(N, true);
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (sqrt(pow(h[i].first - h[j].first, 2) + pow(h[i].second - h[j].second, 2)) < d)
                {
                    ok[i] = false;
                    ok[j] = false;
                }
            }
        }

        int s = 0;
        for (int i = 0; i < N; i++)
        {
            if (ok[i])
            {
                s++;
            }
        }

        cout << N - s << " sour, "
             << s << " sweet\n";
    }

    return 0;
}