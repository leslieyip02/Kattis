#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

map<int, vector<int>> rows;
map<int, vector<int>> cols;
map<pair<int, int>, int> cells;

void fly_from(int x1, int y1)
{
    // cout << "Looking from " << x1 << ", " << y1 << endl;
    // check if L-shape path is possible
    int o[2][2] = { { 1, 2 }, { 2, 1 } };
    for (int i = 0; i < 2; i++)
    {
        int o1 = o[i][0];
        int o2 = o[i][1];

        auto row_itr = find(rows[y1].begin(), rows[y1].end(), x1);
        for (int j = -1; j < 2; j += 2)
        {
            // cout << "j: " << j << endl;
            auto x2_itr = next(row_itr, j * o1);
            if (x2_itr >= rows[y1].begin() && x2_itr < rows[y1].end())
            {
                int x2 = *x2_itr;
                auto y2_itr = find(cols[x2].begin(), cols[x2].end(), y1);
                for (int k = -1; k < 2; k += 2)
                {
                    // cout << "k: " << k << endl;
                    auto y2_itr_a = next(y2_itr, k * o2);
                    if (y2_itr_a >= cols[x2].begin() && y2_itr_a < cols[x2].end())
                    {
                        int y2 = *y2_itr_a;
                        // cout << "Displacement A: " << j * o1 << ", " << k * o2 << endl;
                        // cout << x2 << ", " << y2 << ": " << cells[{x2, y2}] << endl;
                        if ((cells[{x2, y2}] > 0 &&
                            cells[{x1, y1}] + 1 < cells[{x2, y2}]) ||
                            cells[{x2, y2}] == -1)
                        {
                            cells[{x2, y2}] = cells[{x1, y1}] + 1;
                            fly_from(x2, y2);
                        }                
                    }
                }      
            }
        }

        auto col_itr = find(cols[x1].begin(), cols[x1].end(), y1);
        for (int j = -1; j < 2; j += 2)
        {
            // cout << "j: " << j << endl;
            auto y3_itr = next(col_itr, j * o1);
            if (y3_itr >= cols[x1].begin() && y3_itr < cols[x1].end())
            {
                int y3 = *y3_itr;
                auto x3_itr = find(rows[y3].begin(), rows[y3].end(), x1);
                for (int k = -1; k < 2; k += 2)
                {
                    // cout << "k: " << k << endl;
                    auto x3_itr_a = next(x3_itr, k * o2);
                    if (x3_itr_a >= rows[y3].begin() && x3_itr_a < rows[y3].end())
                    {
                        int x3 = *x3_itr_a;
                        // cout << "Displacement B: " << k * o2 << ", " << j * o1 << endl;
                        // cout << x3 << ", " << y3 << ": " << cells[{x3, y3}] << endl;
                        if ((cells[{x3, y3}] > 0 &&
                            cells[{x1, y1}] + 1 < cells[{x3, y3}]) ||
                            cells[{x3, y3}] == -1)
                        {
                            cells[{x3, y3}] = cells[{x1, y1}] + 1;
                            fly_from(x3, y3);
                        }                
                    }
                }      
            }
        }
    }
}

int main()
{
    int n, sx, sy, tx, ty, x, y;
    cin >> n >> sx >> sy >> tx >> ty;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        
        // store x, y, and moves to get to cell
        pair<int, int> cell = make_pair(x, y);
        cells.insert({cell, -1});
        
        if (!rows.emplace(y, vector<int>({x})).second)
            rows[y].push_back(x);

        if (!cols.emplace(x, vector<int>({y})).second)
            cols[x].push_back(y);
    }

    for (auto itr = rows.begin(); itr != rows.end(); itr++)
        sort(itr->second.begin(), itr->second.end());

    for (auto itr = cols.begin(); itr != cols.end(); itr++)
        sort(itr->second.begin(), itr->second.end());

    // set start cell move value
    cells[{sx, sy}] = 0;
    fly_from(sx, sy);

    cout << cells[{tx, ty}] << endl;

    return 0;
}
