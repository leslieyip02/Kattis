#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(void)
{
    int n, m;
    vector<pair<int, int>> calls;
    cin >> n >> m;

    do
    {
        for (int i = 0; i < n; i++)
        {
            int src, dest, start, dur;
            cin >> src >> dest >> start >> dur;
            pair<int, int> call = make_pair(start, dur);
            calls.push_back(call);
        }
        
        for (int i = 0; i < m; i++)
        {
            int start, dur;
            cin >> start >> dur;

            if (dur == 0)
            {
                cout << 0 << endl;
                continue;
            }

            int active = 0;
            for (pair<int, int> call : calls)
            {
                if ((start < call.first + call.second && start + dur >= call.first + call.second) ||
                    (call.first < start + dur && call.first + call.second >= start + dur))
                    active++;    
            }
            cout << active << endl;
        }

        cin >> n >> m;
        calls.clear();
    }
    while (n != 0 && m != 0);

    return 0;
}