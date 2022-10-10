#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long t, p, r, f, n;
    cin >> t;

    while (t--)
    {
        cin >> p >> r >> f;

        for (n = 0; p <= f; n++)
            p *= r;

        cout << n << '\n';
    }

    return 0;
}