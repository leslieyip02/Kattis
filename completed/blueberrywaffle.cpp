#include <iostream>
using namespace std;

int main()
{
    int r, f;
    cin >> r >> f;

    int a = f % (2 * r);
    cout << (a < r / 2.0 || a > r * 1.5 ? "up" : "down") << '\n';

    return 0;
}