#include <iostream>
using namespace std;

int main()
{
    int r, b, a, l, w;
    cin >> r >> b;
    
    a = r + b;
    for (l = 3; l <= a / 3; l++)
    {
        if (a % l == 0)
        {
            w = a / l;
            if (2 * l + 2 * w - 4 == r)
                break;
        }
    }
    
    cout << w << ' ' << l << '\n';
    return 0;
}