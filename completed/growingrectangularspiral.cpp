#include <iostream>
using namespace std;

int main()
{
    int p, n, x, y;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> n >> x >> y;
        if (x == y)
            cout << n << " NO PATH" << endl;
        else if (x < y)
            cout << n << " 2 " << x << " " << y << endl; 
        else if (y <= 3)
            cout << n << " NO PATH" << endl;
        else
            cout << n << " 6 1 2 3 "
                << (x + 3) - (y - 2) << " "
                << x + 2 << " "
                << x + 3 << endl;
    }

    return 0;
}