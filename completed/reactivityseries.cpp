#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, a, b;
    cin >> n >> k;

    // stores the metals that are less reactve than itself
    vector<vector<int>> m(n, vector<int>());
    // counts of metals more reactive than itself
    vector<int> c(n, 0);

    while (k--)
    {
        cin >> a >> b;
        m[a].push_back(b);
        c[b]++;
    }

    int current = -1;
    for (int i = 0; i < n; i++)
    {
        // if c[i] is 0, i is the most reactive metal
        if (c[i] == 0)
        {
            // if there is more than 1 such metal,
            // then the data is insufficient
            if (current != -1)
            {
                cout << "back to the lab\n";
                return 0;
            }

            current = i;
        }
    }

    vector<int> order;
    while (current != -1)
    {
        order.push_back(current);

        vector<int> next = m[current];
        current = -1;
        for (int i : next)
        {
            c[i]--;

            // find the next most reactive metal
            if (c[i] == 0)
            {
                // again, if there is more than 1 such metal,
                // the data is insufficient
                if (current != -1)
                {
                    cout << "back to the lab\n";
                    return 0;
                }

                current = i;
            }
        }
    }
    
    for (int i : order)
        cout << i << " ";
    cout << '\n';

    return 0;
}