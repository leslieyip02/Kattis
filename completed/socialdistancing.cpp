#include <iostream>
using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;

    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = s + a[0];

    int c = 0;
    for (int i = 0; i < n; i++)
        c += (a[i + 1] - a[i] - 2) / 2;
    cout << c << endl;

    return 0;
}