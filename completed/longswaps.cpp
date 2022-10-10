#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s, t;
    int k, i;
    
    cin >> s >> k;
    if (k <= s.length() / 2)
    {
        cout << "Yes\n";
        return 0;
    }

    i = s.length() - k;
    t = s;
    sort(t.begin(), t.end());
    
    cout << (s.substr(i, k - i) == t.substr(i, k - i) ? "Yes\n" : "No\n");
    
    return 0;
}
