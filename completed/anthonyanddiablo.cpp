#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

int main()
{
    double a, n;
    std::cin >> a >> n;

    // let A be the area of a circle with radius r
    double r = sqrt(a / PI);
    
    std::cout << (n >= 2 * PI * r ? "Diablo is happy!\n" : "Need more materials!\n");

    return 0;
}