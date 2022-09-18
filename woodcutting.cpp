#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, wi, s;
    cin >> t;

    while (t--)
    {
        cin >> n;
        unsigned long long w[n];

        for (int i = 0; i < n; i++)
        {
            cin >> wi;
            unsigned long long c = 0;
            for (int j = 0; j < wi; j++)
            {
                cin >> s;
                c += s;
            }
            w[i] = c;
        }

        sort(w, w + n);

        unsigned long long total = 0, p = 0;
        for (int i = 0; i < n; i++)
            total += p += w[i];

        double avg = (double) total / n;
        cout << setprecision(7) << avg << '\n';
    }

    return 0;
}