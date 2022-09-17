#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, v, i;
    map<int, int> A;

    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> v;
        if (A.find(v) == A.end())
            A.insert({ v, 0 });
        A[v]++;
    }

    vector<int> f;
    for (pair<int, int> itr : A)
        f.push_back(itr.second);
    sort(f.begin(), f.end(), greater<int>());

    while (k > 0)
    {
        i = 0;
        while (i < f.size() && f[i] == f[i + 1])
            i++;

        for (; i >= 0 && k > 0; i--, k--)
            f[i]--;
    }

    cout << f[0] << '\n';

    return 0;
}