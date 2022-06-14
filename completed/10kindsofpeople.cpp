#include <iostream>
#include <string>
#include <vector>
using namespace std;

int r, c;
vector<vector<int>> grid;
// coordinate offset for north, south, east and west
int offset[4][2] = {{ 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 }};

void flood(int current_x, int current_y, int fill);

int main()
{
    cin >> r >> c;

    // store strings as ints
    for (int j = 0; j < r; j++)
    {
        vector<int> row;
        string row_string;
        cin >> row_string;
        for (int i = 0; i < c; i++)
        {
            row.push_back((int)row_string[i] - '0');
        }
        grid.push_back(row);
    }

    // flood fill adjacent '0's or '1's
    // if the value of 2 points are equal, they are connected by a path
    // use even numbers for '0's and odd numbers for '1's
    int even = 2;
    int odd = 3;

    for (int j = 0; j < r; j++)
    {
        for (int i = 0; i < c; i++)
        {
            if (grid[j][i] == 0)
            {
                flood(i, j, even);
                even += 2;
            }
            else if (grid[j][i] == 1)
            {
                flood(i, j, odd);
                odd += 2;
            }
        }
    }

    // debug print grid
    // for (int j = 0; j < r; j++)
    // {
    //     for (int i = 0; i < c; i++)
    //     {
    //         cout << grid[j][i] << " ";
    //     }
    //     cout << '\n';
    // }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start_x, start_y, end_x, end_y;
        cin >> start_y >> start_x >> end_y >> end_x;

        // convert coordinates to 0-indexed array coordinates
        start_x--;
        start_y--;
        end_x--;
        end_y--;

        if (grid[start_y][start_x] == grid[end_y][end_x])
            cout << ((int) grid[start_y][start_x] % 2 == 0 ? "binary" : "decimal") << endl;
        else
            cout << "neither" << endl;
    }
    
    return 0;
}

void flood(int current_x, int current_y, int fill)
{
    // cout << "filling " << current_x << ", " << current_y << endl;
    int value = grid[current_y][current_x];
    grid[current_y][current_x] = fill;
    for (int i = 0; i < 4; i++)
    {
        int next_x = current_x + offset[i][0];
        int next_y = current_y + offset[i][1];
        // cout << "next " << next_x << ", " << next_y << endl;
        // fill adjacent 
        if (next_x >= 0 && next_x < c &&
            next_y >= 0 && next_y < r &&
            grid[next_y][next_x] != fill &&
            grid[next_y][next_x] == value)

            flood(next_x, next_y, fill);
    }
}