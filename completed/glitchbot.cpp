#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int n;
string m[] = { "Forward", "Left", "Right" };
pair<int, int> o[] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };


pair<int, int> go(string path[])
{
    int d = 0;
    pair<int, int> e = { 0, 0 };

    for (int i = 0; i < n; i++)
    {
        if (path[i] == "Left")
            d = (d + 3) % 4;
        else if (path[i] == "Right")
            d = (d + 1) % 4;
            
        if (path[i] == "Forward")
        {
            e.first += o[d].first;
            e.second += o[d].second;
        }
    }

    return e;
}

int main()
{
    pair<int, int> t;
    cin >> t.first >> t.second >> n;

    string p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    for (int i = 0; i < n; i++)
    {
        string q[n];
        
        for (string d : m)
        {
            if (d == p[i])
                continue;
                
            copy(p, p + n, q);
            q[i] = d;
            if (go(q) == t)
            {
                cout << i + 1 << " " << d << "\n";
                return 0;
            }
        }
    }
}