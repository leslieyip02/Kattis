#include <iostream>
using namespace std;

int main()
{
    double c;
    cin >> c;
    
    double x = c / 2;
    cout << (c > 1.0 ? 0.25 : x * x) << '\n';
    
    return 0;
}