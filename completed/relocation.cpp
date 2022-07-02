#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, q, x, a, b, c;
    cin >> n >> q;

    map<int, int> locations = map<int, int>();
    for (int i = 1; i <= n; i++)
        cin >> locations[i];

    for (int i = 0; i < q; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
            locations[b] = c;
        else
            cout << abs(locations[b] - locations[c]) << endl;
    }

    return 0;
}