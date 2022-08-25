#include <iostream>
#include <math.h>
using namespace std;

#define ull unsigned long long

int main()
{
    ull n, m;
    cin >> n >> m;

    ull c = 0;
    for (ull i = 1; i <= (ull) sqrt(m); i++)
    {
        if (m % i == 0)
        {
            ull f = m / i;
            if (f == i)
                c++;
            else if (f <= n)
                c += 2;
        }
    }

    cout << c << endl;

    return 0;
}