#include <iostream>
#include <utility>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    bool f[n][m];
    string row;
    for (int i = 0; i < n; i++)
    {
        cin >> row;
        for (int j = 0; j < m; j++)
            f[i][j] = row[j] == '$' ? true : false;
    }

    int c = 1;
    for (int i = 0; i < m; i++)
    {
        bool blank = true;
        for (int j = 0; j < n; j++)
        {
            if (f[j][i])
            {
                blank = false;
                break;
            }
        }

        if (blank)
            c++;
    }    

    cout << c << '\n';

    return 0;
}