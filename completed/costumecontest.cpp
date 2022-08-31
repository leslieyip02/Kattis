#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string cat;
    map<string, int> cats;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cat;
        if (cats.find(cat) == cats.end())
            cats.insert({ cat, 0 });
        cats[cat]++;
    }

    int least = n;
    vector<string> names;
    for (pair<string, int> p : cats)
    {
        if (p.second < least)
        {
            least = p.second;
            names.clear();
        }

        if (p.second <= least)
            names.push_back(p.first);
    }

    sort(names.begin(), names.end());
    for (string name : names)
        cout << name << '\n';     

    return 0;
}