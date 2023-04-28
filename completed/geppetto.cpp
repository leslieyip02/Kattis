#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;
vector<set<int>> ingredients;
vector<bool> selected;

int ways(int i)
{
    if (i == n)
    {
        return 1;
    }

    int p = ways(i + 1);

    bool ok = true;
    for (auto j : ingredients[i])
    {
        if (selected[j])
        {
            ok = false;
            break;
        }
    }

    if (ok)
    {
        selected[i] = true;
        p += ways(i + 1);
        selected[i] = false;
    }

    return p;
}

int main()
{
    cin >> n >> m;
    ingredients.resize(n, set<int>());
    selected.resize(n, false);

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        ingredients[a - 1].insert(b - 1);
        ingredients[b - 1].insert(a - 1);
    }

    cout << ways(0) << '\n';

    return 0;
}