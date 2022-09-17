#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int c[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);

    int s = 0;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] != t)
        {
            s += c[i];
            t = c[i];
        }
        t++;
    }

    cout << s << '\n';

    return 0;
}