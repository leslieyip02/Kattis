#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main()
{
    int T;
    ull N, M, a, b, d;
    cin >> T;
    while (T--)
    {
        cin >> N >> M >> a >> b >> d;
        if (b < a)
        {
            b += N;
        }
        cout << ((b + (b - a) + d) % (N + 1) <= N - M ? "YES" : "NO") << '\n';
    }
    return 0;
}
