#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

int main()
{
    int h, w;
    ull s;
    cin >> h >> w >> s;

    string r;
    int k = 1;
    while (h--)
    {
        cin >> r;
        for (int i = 0; i < w; i++)
        {
            if (r[i] == '.')
            {
                k++;
            }
        }
    }

    cout << "Your destination will arrive in " << k << string(log10(s), '0') << " meters\n";
    return 0;
}
