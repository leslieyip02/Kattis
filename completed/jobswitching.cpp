#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    int c = 0;
    for (int i = 0; i < n; i++)
    {
        while (p[i] != i + 1)
        {
            swap(p[i], p[p[i] - 1]);
            c++;
        }
    }

    cout << c << '\n';

    return 0;
}
