#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t[43201] = { 0 };

    int n, di, ti;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> di >> ti;
        for (int j = 0; j < 3; j++, ti -= di)
            t[ti]++;
    }

    cout << ceil(*max_element(t, t + 43201) / 2.0) << endl;

    return 0;
}