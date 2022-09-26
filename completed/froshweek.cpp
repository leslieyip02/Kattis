#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, i, j, k;
    cin >> n >> m;
    
    int t[n], l[m];
    
    for (i = 0; i < n; i++)
        cin >> t[i];
        
    for (i = 0; i < m; i++)
        cin >> l[i];
        
    sort(t, t + n);
    sort(l, l + m);

    k = 0;
    for (i = 0, j = 0; i < m; i++)
    {
        if (l[i] >= t[j])
        {
            j++;
            k++;
        }
    }

    cout << k << '\n';
    
    return 0;
}