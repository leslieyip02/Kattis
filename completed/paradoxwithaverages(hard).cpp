#include <iostream>
using namespace std;

void solve()
{
    int ncs, ne;
    unsigned long long tcs, te;
    cin >> ncs >> ne;

    int scs[ncs];
    int se[ne];

    tcs = te = 0;

    for (int i = 0; i < ncs; i++)
    {
        cin >> scs[i];
        tcs += scs[i];
    }

    for (int i = 0; i < ne; i++)
    {
        cin >> se[i];
        te += se[i];
    }

    double avgcs = (double) tcs / ncs;
    double avge = (double) te / ne;

    int c = 0;
    for (int i = 0; i < ncs; i++)
    {
        if ((tcs - scs[i]) / (ncs - 1.0) > avgcs &&
            (te + scs[i]) / (ne + 1.0) > avge)
            c++;
    }

    cout << c << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}