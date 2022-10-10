#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    deque<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    sort(t.begin(), t.end());

    int s[n];
    for (int i = n - 1; !t.empty(); i--)
    {
        s[i] = t.front();
        t.pop_front();
        
        if (!t.empty())
        {
            i--;
            s[i] = t.back();
            t.pop_back();
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (abs(s[i] - s[i - 1]) > abs(s[i + 1] - s[i]))
        {
            cout << "impossible\n";
            return 0;
        }
    }
    
    for (int i : s)
        cout << i << " ";
    cout << '\n';
            
    return 0;
}