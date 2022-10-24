#include <iostream>
using namespace std;

int main()
{
    int n, m, g, c;
    cin >> n >> m;

    c = m;
    while (m--)
    {
        cin >> g;
        if (n >= g)
        {
            n -= g;
            c--;
        }
    }

    cout << c << '\n';
    
    return 0;
}