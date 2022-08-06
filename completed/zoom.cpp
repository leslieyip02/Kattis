#include <iostream>
using namespace std;

int main()
{
    int n, k, x;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (i % k == 0)
            cout << x << " ";
    }
    cout << endl;

    return 0;
}