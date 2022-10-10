#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    // every minute, 
    // the minute hand moves 360° / 60° = 6°,
    // the hour hand moves 30° / 60° = 0.5°
    // difference = 5.5° = 55

    int a;
    cin >> a;

    int i = 0;
    double m = (a + 3600 * i) / 55.0;
    while (floor(m) != m)
        m = (a + 3600 * ++i) / 55.0;

    cout << setfill('0') 
        << setw(2) << (int) m / 60 << ':'
        << setw(2) << (int) m % 60 << '\n';

    return 0;
}