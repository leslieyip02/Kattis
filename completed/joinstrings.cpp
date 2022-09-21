#include <bits/stdc++.h>
using namespace std;

const int M = 100000;
string s[M];
vector<int> order[M];

// recursively print all following strings
 void join(int i)
 {
     cout << s[i];
     for (int j : order[i])
         join(j);
 }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> s[i];

    if (n == 1)
    {
        cout << s[0];
        return 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        order[--a].push_back(--b);
    }

    // last string to join to is the root
    join(a);

    return 0;
}