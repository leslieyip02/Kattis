#include <iostream>
using namespace std;

int main()
{
    unsigned long long a, b;
    cin >> a >> b;

    unsigned long long c = 0;
    if (a % b == 0)
        for (auto i = b; i <= a; i += b)
            if (a % i == 0)
                c++;

    cout << c << '\n';

    return 0;
}