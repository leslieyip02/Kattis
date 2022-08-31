#include <iostream>
using namespace std;

int main()
{
    int b, d, c, l;
    cin >> b >> d >> c >> l;
    
    bool possible = false;
    for (int i = 0; i < l / b + 1; i++)
    {
        for (int j = 0; j < (l - i * b) / d + 1; j++)
        {
            for (int k = 0; k < (l - i * b - j * d) / c + 1; k++)
            {
                if (i * b + j * d + k * c == l)
                {
                    cout << i << ' ' << j << ' ' << k << '\n';
                    possible = true;
                }
            }
        }
    }

    if (!possible)
        cout << "impossible\n";

    return 0;
}