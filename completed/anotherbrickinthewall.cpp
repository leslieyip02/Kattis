#include <iostream>
using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        int brick;
        cin >> brick;

        x += brick;
        if (x == w)
        {
            x = 0;
            y++;
            if (y == h) break;
        }
        else if (x > w)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}