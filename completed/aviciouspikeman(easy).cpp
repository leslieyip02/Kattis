#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, tMax, t0, a, b, c;
    cin >> n >> tMax;
    long long t[n];
    cin >> a >> b >> c >> t[0];

    for (int i = 1; i < n; i++)
        t[i] = (a * t[i - 1] + b) % c + 1;
    sort(t, t + sizeof(t) / sizeof(t[0]));

    int tElapsed = 0;
    int solved = 0;
    long long penalty = 0;

    for (int i = 0; i < n; i++)
    {
        tElapsed += t[i];
        if (tElapsed > tMax)
            break;

        solved++;   
        penalty = (penalty + tElapsed) % 1000000007;
    }

    cout << solved << " " << penalty << endl;

    return 0;
}