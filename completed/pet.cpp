#include <iostream>

int main()
{
    int s;
    int max = 0;
    int max_index = 0;

    for (int i = 1; i <= 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            std::cin >> s;
            sum += s;
        }
        if (sum > max)
        {
            max = sum;
            max_index = i;
        }
    }

    std::cout << max_index << " " << max << "\n";
    return 0;
}