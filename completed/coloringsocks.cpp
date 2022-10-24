#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int s, c, k;
    cin >> s >> c >> k;

    int d[s];
    for (int i = 0; i < s; i++)
        cin >> d[i];

    sort(d, d + s);

    int n = 0;
    vector<int> ld;
    for (int i = 0; i < s; i++)
    {
        if (ld.empty() || d[i] - ld.front() > k || ld.size() == c)
        {
            ld.clear();
            n++;
        }

        ld.push_back(d[i]);
    }

    cout << n << '\n';

    return 0;
}