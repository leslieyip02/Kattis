#include <iostream>
using namespace std;

#define ull unsigned long long
#define M 1000000007

int main()
{
    int T;
    ull d, c, b;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        c = 1;
        b = 9 % M;
        cin >> d;
        d -= 1;
        
        while (d > 0)
        {
            if (d % 2 == 1)
                c = (c * b) % M;
            d >>= 1;
            b = (b * b) % M;
        }
        c = 8 * c % M;

        cout << c << endl;
    }

    return 0;
}