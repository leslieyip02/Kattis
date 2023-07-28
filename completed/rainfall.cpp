#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double L, K, T1, T2, H, F1, F2;
    cin >> L >> K >> T1 >> T2 >> H;

    if (H < L)
    {
        F1 = F2 = H;
    }
    else
    {
        double a = T1;
        double b = -K * (T1 + T2) - H;
        double c = L * K;
        double R = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        F2 = R * T1;
        F1 = H == L ? L : F2;
    }
    cout << setprecision(8) << F1 << ' ' << F2 << '\n';

    return 0;
}