#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, int> g;
    int x;

    int a = n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (g.find(x) != g.end())
            a = min(i - g[x], a);

        g[x] = i;
    }

    cout << a << '\n';    

    return 0;
}