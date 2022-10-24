#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, d, h, m, x, y;
    char v;
    
    cin >> n;
    while (n--)
    {
        cin >> v >> d >> h >> m;

        if (v == 'B')
            d *= -1;
        
        x = floor((m + d) / 60.0);
        x = (x + h + 24) % 24;
        
        y = (m + d + 120) % 60;

        cout << x << ' ' << y << '\n';
    }
    
    return 0;
}