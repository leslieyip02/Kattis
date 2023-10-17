#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int shake(int r, int s, int R, int S, vector<vector<bool>> seats)
{
    int c = 0;
    for (int i = max(r - 1, 0); i < min(r + 2, R); i++)
    {
        for (int j = max(s - 1, 0); j < min(s + 2, S); j++)
        {
            if (i == r && j == s)
            {
                continue;
            }
            if (seats[i][j])
            {
                c++;
            }
        }
    }
    return c;
}

int main()
{
    int R, S;
    cin >> R >> S;

    string row;
    vector<vector<bool>> seats(R, vector<bool>(S, false));
    for (int i = 0; i < R; i++)
    {
        cin >> row;
        for (int j = 0; j < S; j++)
        {
            seats[i][j] = row[j] == 'o';
        }
    }

    int c = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < S; j++)
        {
            if (seats[i][j])
            {
                c += shake(i, j, R, S, seats);
            }
        }
    }
    c /= 2;

    int d = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < S; j++)
        {
            if (!seats[i][j])
            {
                d = max(shake(i, j, R, S, seats), d);
            }
        }
    }
    cout << c + d << '\n';

    return 0;
}