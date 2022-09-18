#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n;

    double l = 0;
    while (n--)
    {
        cin >> a >> b >> c;

        double s = (a + b + c) / 2.0;
        double t = sqrt(s * (s - a) * (s - b) * (s - c));
        double cm = 0.5 * sqrt(2 * a * a + 2 * b * b - c * c);
        double bm = 0.5 * c;

        double scbm = t / (a * bm);
        double scam = t / (b * bm);
        
        double sbcm = bm * scbm / cm;
        double sacm = bm * scam / cm;

        l += a * sbcm;
        l += b * sacm;
    }

    cout << setprecision(10) << l << '\n';

    return 0;
}