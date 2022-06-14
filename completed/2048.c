#include <stdio.h>

int main(void)
{
    // store 4 x 4 grid
    int grid[4][4], dir;

    // read input
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%i", &grid[i][j]);
        }
    }
    scanf("%i", &dir);

    // helper functions
    void slide(int grid[4][4], int dir);
    void merge(int grid[4][4], int dir);

    // slide -> combine -> slide
    slide(grid, dir);
    merge(grid, dir);
    slide(grid, dir);

    // print output
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%i ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void slide(int grid[4][4], int dir)
{
    // slide left
    if (dir == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            int col = 0;
            // insert all non-zero numbers
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j] != 0)
                {
                    grid[i][col] = grid[i][j];
                    col++;
                }
            }
            // replace the rest with '0's
            while (col < 4)
            {
                grid[i][col] = 0;
                col++;
            }
        }
    }
    // slide up
    else if (dir == 1)
    {
        for (int j = 0; j < 4; j++)
        {
            int row = 0;
            for (int i = 0; i < 4; i++)
            {
                if (grid[i][j] != 0)
                {
                    grid[row][j] = grid[i][j];
                    row++;
                }
            }
            while (row < 4)
            {
                grid[row][j] = 0;
                row++;
            }
        }
    }
    // slide right
    else if (dir == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            int col = 3;
            for (int j = 3; j >= 0; j--)
            {
                if (grid[i][j] != 0)
                {
                    grid[i][col] = grid[i][j];
                    col--;
                }
            }
            while (col >= 0)
            {
                grid[i][col] = 0;
                col--;
            }
        }
    }
    // slide down
    else
    {
        for (int j = 0; j < 4; j++)
        {
            int row = 3;
            for (int i = 3; i >= 0; i--)
            {
                if (grid[i][j] != 0)
                {
                    grid[row][j] = grid[i][j];
                    row--;
                }
            }
            while (row >= 0)
            {
                grid[row][j] = 0;
                row--;
            }
        }
    }
    
    return;
}

void merge(int grid[4][4], int dir)
{
    // merge left
    if (dir == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // if numbers are equal, add them up
                if (grid[i][j] == grid[i][j + 1])
                {
                    grid[i][j] *= 2;
                    grid[i][j + 1] = 0;
                }
            }
        }
    }
    // merge up
    else if (dir == 1)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i < 3; i++)
            {
                if (grid[i][j] == grid[i + 1][j])
                {
                    grid[i][j] *= 2;
                    grid[i + 1][j] = 0;
                }
            }
        }
    }
    // merge right
    else if (dir == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 3; j > 0; j--)
            {
                if (grid[i][j] == grid[i][j - 1])
                {
                    grid[i][j] *= 2;
                    grid[i][j - 1] = 0;
                }
            }
        }
    }
    // merge down
    else
    {
        for (int j = 0; j < 4; j++)
        {
            for (int i = 3; i > 0; i--)
            {
                if (grid[i][j] == grid[i - 1][j])
                {
                    grid[i][j] *= 2;
                    grid[i - 1][j] = 0;
                }
            }
        }
    }

    return;
}
