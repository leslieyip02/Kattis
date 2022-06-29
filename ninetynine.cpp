#include <iostream>
using namespace std;

int main()
{
    int x = 1;

    do
    {
        cout << x << endl;
        cin >> x;
        
        if (x == 97 || x == 98)
            x = 99;
        else if ((x + 1) % 3 == 0)
            x += 1;
        else
            x += 2;
    }
    while (x < 99);
    cout << 99 << endl;

    return 0;
}