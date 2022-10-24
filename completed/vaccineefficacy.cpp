#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string p;

    int v = 0;
    int nv = 0;

    int vc[3] = { 0 };
    int nvc[3] = { 0 };

    for (int i = 0; i < n; i++)
    {
        cin >> p;

        if (p[0] == 'Y')
        {
            for (int j = 0; j < 3; j++)
                if (p[j + 1] == 'Y') vc[j]++;

            v++;
        }
        else
        {
            for (int j = 0; j < 3; j++)
                if (p[j + 1] == 'Y') nvc[j]++;

            nv++;
        }
    }

    double vr, nvr, eff;
    for (int i = 0; i < 3; i++)
    {
        vr = (double) vc[i] / v;
        nvr = (double) nvc[i] / nv;
        eff = (nvr - vr) / nvr * 100.0;
        
        if (eff <= 0)
            cout << "Not Effective\n";
        else
            cout << setprecision(10) << eff << '\n';
    }

    return 0;
}