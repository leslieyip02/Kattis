#include <iostream>
using namespace std;

int main()
{
    int n, s, d;
    cin >> n;

    while (n--)
    {
        cin >> s >> d;

        int a = s + d;
        if (d > s || a % 2 != 0)
        {
            cout << "impossible\n";
        }
        else
        {
            a /= 2;
            cout << a << ' ' << a - d << '\n';
        }
    }

    return 0;
}