#include <iostream>
#include <vector>
using namespace std;

#define ull unsigned long long

int main()
{
    ull N, C, m, s, f;
    cin >> N >> C;

    vector<ull> w(N);
    for (int i = 0; i < N; i++)
    {
        cin >> w[i];
    }

    m = 0;
    for (int i = 0; i < N; i++)
    {
        s = C;
        f = 0;
        for (int j = i; j < N; j++)
        {
            if (w[j] <= s)
            {
                s -= w[j];
                f++;
            }
        }
        m = max(f, m);
    }

    cout << m << '\n';
    return 0;
}