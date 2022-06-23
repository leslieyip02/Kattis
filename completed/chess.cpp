#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int board[8][8];

vector<pair<int, int>> check_diagonal(int sx, int sy, int tx, int ty, int current)
{
    // cout << "looking into " << sx << ", " << sy << ": " << board[sy - 1][sx - 1] << endl;
    vector<pair<int, int>> shortest = vector<pair<int, int>>();

    if (sx == tx && sy == ty)
    {
        pair<int, int> cell = make_pair(sx, sy);
        shortest.push_back(cell);
        return shortest;
    }

    if (board[sy - 1][sx - 1] == 0 ||
        (current + 1 < board[sy - 1][sx - 1]))
        board[sy - 1][sx - 1] = current + 1;
    else
        return shortest;

    int ax = sx + min(8 - sx, 8 - sy);
    int ay = sy + min(8 - sx, 8 - sy);

    int bx = sx + min(8 - sx, sy - 1);
    int by = sy - min(8 - sx, sy - 1);

    int cx = sx - min(sx - 1, 8 - sy);
    int cy = sy + min(sx - 1, 8 - sy);

    int dx = sx - min(sx - 1, sy - 1);
    int dy = sy - min(sx - 1, sy - 1);

    // check all 4 directions
    // top right
    while (ax > sx && ay > sy)
    {
        vector<pair<int, int>> cells = check_diagonal(ax, ay, tx, ty, current + 1);
        if (!cells.empty())
            if (shortest.empty() || cells.size() < shortest.size())
                shortest = cells;

        ax--;
        ay--;
    }

    // bottom right
    while (bx > sx && by < sy)
    {
        vector<pair<int, int>> cells = check_diagonal(bx, by, tx, ty, current + 1);
        if (!cells.empty())
            if (shortest.empty() || cells.size() < shortest.size())
                shortest = cells;

        bx--;
        by++;
    }

    // top left
    while (cx < sx && cy > sy)
    {
        vector<pair<int, int>> cells = check_diagonal(cx, cy, tx, ty, current + 1);
        if (!cells.empty())
            if (shortest.empty() || cells.size() < shortest.size())
                shortest = cells;

        cx++;
        cy--;
    }

    // bottom left
    while (dx < sx && dy < sy)
    {
        vector<pair<int, int>> cells = check_diagonal(dx, dy, tx, ty, current + 1);
        if (!cells.empty())
            if (shortest.empty() || cells.size() < shortest.size())
                shortest = cells;

        dx++;
        dy++;
    }

    if (!shortest.empty())
    {
        pair<int, int> cell = make_pair(sx, sy);
        shortest.push_back(cell);
    }

    return shortest;
}

int main()
{
    int i, j;
    cin >> i;
    for (j = 0; j < i; j++)
    {
        int x1, y1, x2, y2;
        char a, b;

        cin >> a >> y1 >> b >> y2;
        x1 = (int) a - 64;
        x2 = (int) b - 64;

        if ((x1 + y1) % 2 != (x2 + y2) % 2)
        {
            cout << "Impossible" << endl;
            continue;
        }

        for (int s = 0; s < 8; s++)
            for (int t = 0; t < 8; t++)
                board[s][t] = 0;

        vector<pair<int, int>> cells = check_diagonal(x1, y1, x2, y2, 0);
        cout << cells.size() - 1 << " ";
        for (auto itr = cells.rbegin(); itr != cells.rend(); itr++)
        {
            pair<int, int> cell = *itr;
            cout << (char) (cell.first + 64) << " " << cell.second << " ";
        }
        cout << endl;
    }

    return 0;
}