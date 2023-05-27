#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, d, a;
    cin >> n >> d;

    map<int, int> c;
    while (n--)
    {
        cin >> a;
        a /= d;

        if (c.find(a) == c.end())
        {
            c.insert({a, 0});
        }

        c[a]++;
    }

    long long w = 0;
    for (auto x : c)
    {
        if (x.second >= 2)
        {
            w += ((x.second / 2.0) * (x.second - 1));
        }
    }

    cout << w << '\n';

    return 0;
}