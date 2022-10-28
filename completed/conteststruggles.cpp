#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, k, d, s;
    cin >> n >> k >> d >> s;

    int t = n * d - k * s;
    double a = (double) t / (n - k);

    if (a < 0 || a > 100)
        cout << "impossible\n";
    else
        cout << setprecision(10) << a << '\n';

    return 0;
}