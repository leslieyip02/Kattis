#include <iostream>
#include <set>
#include <cctype>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string p1, p2;
    set<string> w;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cin >> p1;
            if (i != 0 && *p1.begin() != p2[p2.length() - 1] ||
                w.find(p1) != w.end())
            {
                cout << "Player 1 lost\n";
                return 0;
            }

            w.insert(p1);
        }
        else
        {
            cin >> p2;
            if (*p2.begin() != p1[p1.length() - 1] ||
                w.find(p2) != w.end())
            {
                cout << "Player 2 lost\n";
                return 0;
            }

            w.insert(p2);
        }
    }

    cout << "Fair Game\n";
    return 0;
}