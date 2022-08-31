#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, p, k;
    cin >> n >> p >> k;

    int y[n + 2];
    for (int i = 1; i <= n; i++)
        cin >> y[i];
    y[0] = 0;
    y[n + 1] = k;

    double t = 0;
    for (int i = 0; i <= n; i++)
        t += (y[i + 1] - y[i]) * (100 + p * i) / 100.0;
    cout << setprecision(10) << t << '\n';

    return 0;
}