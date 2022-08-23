#include <iostream>
using namespace std;

int digitSum(int x)
{
    int y = 0;

    while (x >= 10)
    {
        y += x % 10;
        x /= 10;
    }

    return y + x;
}

int main()
{
    int t, n, s, o;
    cin >> t;
    while (t--)
    {
        cin >> n;
        s = digitSum(n) - 1;
        o = 1;

        while (true)
        {
            if (digitSum(n + o) == s)
            {
                cout << n + o << endl;
                break;
            }

            if (digitSum(n - o) == s)
            {
                cout << n - o << endl;
                break;
            }

            o++;
        }
    }

    return 0;
}