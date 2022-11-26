#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, c;
    cin >> n >> k;

    int m = n + 1;
    vector<int> f(k, 0);
    while (n--)
    {
        cin >> c;
        f[--c]++;
    }

    vector<int> s;
    for (int i = 0; i < k; i++)
    {
        if (f[i] < m)
        {
            m = f[i];
            s.clear();
        }
        
        if (f[i] == m)
            s.push_back(i + 1);
    }

    sort(s.begin(), s.end());
    cout << s.size() << '\n';
    for (int i : s)
        cout << i << ' ';
    cout << '\n';

    return 0;
}