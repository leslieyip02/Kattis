#include <iostream>
using namespace std;

int main()
{
    int n, k, x;
    cin >> n >> k;

    while (n--)
    {
        cin >> x;

        while (x % 2 == 0)
        {
            x >>= 1;
            k--;
        }
    }

    cout << (k <= 0) << '\n';

    return 0;
}