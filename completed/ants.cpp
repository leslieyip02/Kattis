#include <iostream>
using namespace std;

int main()
{
    int t, l, n, x;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> l >> n;

        int earliest = 0, latest = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            earliest = max(x > l / 2 ? l - x : x, earliest);
            latest = max(max(x, l - x), latest);
        }
            
        cout << earliest << " " << latest << endl;
    }

    return 0;
}