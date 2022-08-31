#include <iostream>
using namespace std;

int main()
{
    int k, p, q, c;
    p = -1;
    c = 1;
    cin >> k;
    while (k--)
    {
        cin >> q;
        if (q < p)
            c++;
        p = q;
    }

    cout << c << '\n';

    return 0;
}