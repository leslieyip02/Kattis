#include <iostream>
using namespace std;

int main()
{
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        unsigned long remainder = 0;
        for (int j = 0; j < n; j++)
        {
          unsigned long c;
          cin >> c;
          remainder += c % n;
        }
        if (remainder % n == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}