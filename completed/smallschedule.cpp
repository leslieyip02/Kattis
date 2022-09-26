#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int q, m, s, l, r;
    double t, e;
    cin >> q >> m >> s >> l;

    t = ceil((double) l / m) * q;
    r = l % m;
    r = r == 0 ? m : r;
    e = s - (m - r) * q;
    if (e > 0)
        t = ceil(t + ceil(e / m));
    
    cout << (long) t << '\n';
    
    return 0;
}