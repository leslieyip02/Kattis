#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, e, g;
    long long s;
    string comd;
    map<int, priority_queue<int>> pool;

    cin >> n;
    while (n--)
    {
        cin >> comd;
        if (comd == "add")
        {
            cin >> e >> g;
            pool[e].push(g);
        }
        else
        {
            cin >> x;

            s = 0;
            auto quest = pool.lower_bound(x);
            while (!pool.empty())
            {
                if (quest == pool.end())
                    quest--;

                while (quest->first > x && quest != pool.begin())
                    quest--;

                if (quest->first > x)
                    break;

                x -= quest->first;
                s += quest->second.top();
                quest->second.pop();

                if (quest->second.empty())
                    pool.erase(quest);
                
                if (x == 0 || pool.empty())
                    break;

                quest = pool.lower_bound(x);
            }
            
            cout << s << '\n';
        }
    }

    return 0;
}