#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n)
    {
        int r = n;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                r -= r / i;
            }
            while (n % i == 0)
            {
                n /= i;
            }
        }
        if (n > 1)
        {
            r -= r / n;
        }

        cout << r << '\n';
        cin >> n;
    }

    return 0;
}