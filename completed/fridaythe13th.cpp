#include <iostream>
using namespace std;

int main()
{
    int t, d, di, m;
    cin >> t;
    while (t--)
    {
        cin >> d >> m;

        int f13 = 0;
        int p = 6;
        while (m--)
        {
            cin >> di;
            
            if (di >= 13 && (p + 13) % 7 == 5)
                f13++;
            
            p = (p + di) % 7;
        }
        
        cout << f13 << '\n';
    }

    return 0;
}