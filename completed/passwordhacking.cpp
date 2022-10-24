#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string s;

    cin >> n;
    double p[n];
    for (int i = 0; i < n; i++)
        cin >> s >> p[i];    

    sort(p, p + n, greater<double>());

    double e = 0;
    for (int i = 1; i <= n; i++)
        e += i * p[i - 1];

    cout << setprecision(10) << e << '\n';

    return 0;
}