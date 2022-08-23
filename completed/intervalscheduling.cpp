#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    pair<int, int> itv[n];
    for (int i = 0; i < n; i++)
        cin >> itv[i].first >> itv[i].second;
    sort(itv, itv + n, [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    });

    int c = 0;
    int u = -1;
    for (int i = 0; i < n; i++)
    {
        if (itv[i].first >= u)
        {
            c++;
            u = itv[i].second;
        }
    }

    cout << c << endl;

    return 0;
}