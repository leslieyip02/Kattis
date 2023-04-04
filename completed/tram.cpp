#include <iostream>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n;

    double a = 0.0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a += y - x;
    }

    cout << a / n << '\n';

    return 0;
}