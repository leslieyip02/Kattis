#include <iostream>

int main()
{
    int n, k;
    std::cin >> n;

    long long e = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> k;
        if (k < 0)
            e -= k;
    }

    std::cout << e << '\n';
    return 0;
}