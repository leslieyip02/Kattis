#include <iostream>

int main()
{
    int r, c;
    std::cin >> r >> c;

    char map[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            std::cin >> map[i][j];

    for (int k = 0; k <= 4; k++)
    {
        int n = 0;
        for (int y = 0; y < r - 1; y++)
        {
            for (int x = 0; x < c - 1; x++)
            {
                int can_squash = k;
                for (int oy = 0; oy <= 1; oy++)
                {
                    for (int ox = 0; ox <= 1; ox++)
                    {
                        if (map[y + oy][x + ox] == '#')
                            can_squash -= 5;
                        else if (map[y + oy][x + ox] == 'X')
                            can_squash--;
                    }
                }

                if (can_squash == 0)
                    n++;
            }
        }
        
        std::cout << n << '\n';
    }

    return 0;
}