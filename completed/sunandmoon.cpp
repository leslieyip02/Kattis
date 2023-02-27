#include <iostream>
using namespace std;

int main()
{
    int ds, ys, dm, ym;
    cin >> ds >> ys >> dm >> ym;

    int s = -ds;
    int m = -dm;

    while (s != m)
    {
        if (s < m)
        {
            s += ys;
        }
        else
        {
            m += ym;
        }
    }

    cout << s << '\n';

    return 0;
}