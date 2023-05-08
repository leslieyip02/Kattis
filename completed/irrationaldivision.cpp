#include <iostream>
using namespace std;

int main()
{
    int p, q, r;
    cin >> p >> q;

    if (p % 2 == 0)
    {
        r = 0;
    }
    else if (q % 2 == 1)
    {
        r = 1;
    }
    else
    {
        r = p < q ? 2 : 0;
    }

    cout << r << '\n';

    return 0;
}