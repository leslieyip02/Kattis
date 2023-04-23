#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a;
    cin >> n >> a;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int w = 0;
    sort(s.begin(), s.end(), greater<int>());
    while (!s.empty() && s.back() + 1 <= a)
    {
        w++;
        a -= s.back() + 1;
        s.pop_back();
    }

    cout << w << '\n';

    return 0;
}