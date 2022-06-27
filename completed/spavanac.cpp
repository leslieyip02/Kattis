#include <iostream>

int main()
{
    int h, m;
    std::cin >> h >> m;

    if (m < 45)
        h--;
    
    if (h < 0)
        h = 23;

    if (m >= 45)
        m -= 60;
    m += 15;

    std::cout << h << " " << m << "\n";

    return 0;
}