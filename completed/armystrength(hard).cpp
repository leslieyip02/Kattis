#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, ng, nm, s;
    vector<int> g, m;
    cin >> t;

    while (t--)
    {
        cin >> ng >> nm;

        g.clear();
        m.clear();

        for (int i = 0; i < ng; i++)
        {
            cin >> s;
            g.push_back(s);
        }

        for (int i = 0; i < nm; i++)
        {
            cin >> s;
            m.push_back(s);
        }

        sort(g.begin(), g.end(), less<int>());
        sort(m.begin(), m.end(), less<int>());

        while (!g.empty() && !m.empty())
        {
            if (g.back() < m.back())
                g.pop_back();
            else
                m.pop_back();
        }

        cout << (g.empty() ? "Mecha" : "") << "Godzilla\n";
    }

    return 0;
}