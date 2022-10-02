#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int g, m;
    cin >> g;
    m = 1;

    int sins[g];
    unordered_set<int> s;
    for (int i = 0; i < g; i++)
    {
        cin >> sins[i];
        s.insert(sins[i] % m);
    }

    while (s.size() < g)
    {
        s.clear();

        m++;
        for (int i = 0; i < g; i++)
            s.insert(sins[i] % m);
    }

    cout << m << '\n';

    return 0;
}