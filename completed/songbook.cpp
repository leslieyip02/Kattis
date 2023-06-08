#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    cin >> t >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s.begin(), s.end(), greater<int>());

    t *= 60;
    int d = 0;
    while (!s.empty() && t >= s.back())
    {
        d += s.back();
        t -= s.back();
        s.pop_back();
    }

    cout << d << '\n';
    return 0;
}