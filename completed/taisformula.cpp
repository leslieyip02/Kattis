#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;

    double t1, t2, v1, v2, a;
    cin >> t1 >> v1;

    for (int i = 1; i < n; i++)
    {
        cin >> t2 >> v2;
        a += (t2 - t1) * (v1 + v2) * 0.0005;
        t1 = t2;
        v1 = v2;
    }

    cout << setprecision(10) << a << endl;

    return 0;
}