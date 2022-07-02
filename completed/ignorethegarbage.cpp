#include <iostream>

int flipped[7] = { 0, 1, 2, 5, 9, 8, 6 };

int main()
{
    int k;
    while (std::cin >> k)
    {
        while (k > 0)
        {
            std::cout << flipped[k % 7];
            k /= 7;
        }
        std::cout << '\n'; 
    }

    return 0;
}