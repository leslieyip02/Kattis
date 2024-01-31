#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int n, m, k;
    string name;
    unordered_map<string, int> attendance;
    cin >> n;
    while (n--)
    {
        cin >> name;
        attendance[name] = 0;
    }
    cin >> m;
    while (m--)
    {
        cin >> k;
        while (k--)
        {
            cin >> name;
            attendance[name]++;
        }
    }
    vector<pair<string, int>> ordered;
    for (auto pair : attendance)
    {
        ordered.push_back(pair);
    }
    sort(ordered.begin(), ordered.end(),
        [](const pair<string, int> p1, const pair<string, int> p2)
        {
            return p1.second > p2.second;
        }
    );
    for (auto pair : ordered)
    {
        cout << pair.second << ' ' << pair.first << '\n';
    }
    return 0;
}