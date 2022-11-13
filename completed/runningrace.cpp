#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct contestant
{
    int id;
    int mm;
    int ss;
    int laps;

    void completeLap(string t)
    {
        int d = t.find('.');
        int x = stoi(t.substr(0, d));
        int y = stoi(t.substr(d + 1));

        mm += x + (ss + y) / 60;
        ss = (ss + y) % 60;
        laps++;
    }
};

int main()
{
    int l, k, s;
    cin >> l >> k >> s;

    map<int, contestant> contestants;

    int i;
    string lap;
    while (l--)
    {
        cin >> i >> lap;
        if (contestants.find(i) == contestants.end())
            contestants[i] = { i, 0, 0, 0 };

        contestants[i].completeLap(lap);
    }

    vector<contestant> finished;
    for (auto c : contestants)
        if (c.second.laps == k)
            finished.push_back(c.second);

    sort(finished.begin(), finished.end(),
        [](const contestant &a, const contestant &b)
    {
        if (a.mm == b.mm)
            return (a.ss != b.ss) ? a.ss < b.ss :
                a.id < b.id;

        return a.mm < b.mm;
    });

    for (auto c : finished)
        cout << c.id << '\n';

    return 0;
}
