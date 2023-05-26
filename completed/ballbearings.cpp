#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415926535897931;

int main()
{
    int n;
    double D, d, s;

    cin >> n;
    while (n--)
    {
        cin >> D >> d >> s;
        D -= d;
        cout << (int) (PI / asin((d + s) / D)) << '\n';
    }

    return 0;
}