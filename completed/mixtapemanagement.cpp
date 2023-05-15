#include <iostream>
using namespace std;

int main()
{
    int n, p;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        cout << (int) ((double) (i + 100) / n * 200);
        while (p--)
        {
            cout << '0';
        }
        cout << ' ';
    }

    return 0;
}