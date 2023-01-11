#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    bool changed = true;
    while (changed)
    {
        changed = false;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'V')
                {
                    if (grid[i + 1][j] == '.')
                    {   
                        grid[i + 1][j] = 'V';
                        changed = true;
                    }
                    else if (grid[i + 1][j] == '#')
                    {
                        if (j > 0 && grid[i][j - 1] == '.')
                        {
                            grid[i][j - 1] = 'V';
                            changed = true;
                        }
                        
                        if (j < m - 1 && grid[i][j + 1] == '.')
                        {
                            grid[i][j + 1] = 'V';
                            changed = true;
                        }
                    }
                }
            }
        }
    }

    for (string row : grid)
        cout << row << '\n';

    return 0;
}