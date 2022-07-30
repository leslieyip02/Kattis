using System;

class Program
{
    static void Main(String[] args)
    {
        String[] d = Console.ReadLine()
            .Split(" ");
        int r = Convert.ToInt32(d[0]);
        int s = Convert.ToInt32(d[1]);
        int k = Convert.ToInt32(d[2]);
        
        char[][] win = new char[r][];
        for (int i = 0; i < r; i++)
            win[i] = Console.ReadLine()
                .ToCharArray();

        int x = 0, y = 0, max = 0;
        for (int y0 = 1; y0 < r - (k - 2); y0++)
        {
            for (int x0 = 1; x0 < s - (k - 2); x0++)
            {
                int count = 0;
                for (int y1 = 0; y1 < k - 2; y1++)
                {
                    for (int x1 = 0; x1 < k - 2; x1++)
                    {
                        if (win[y0 + y1][x0 + x1] == '*')
                            count++;
                    }
                }
                
                if (count > max)
                {
                    max = count;
                    x = x0;
                    y = y0;
                }
            }
        }
        
        for (int i = 0; i < k; i++)
        {
            win[y - 1][x - 1 + i] = '-';
            win[y + k - 2][x - 1 + i] = '-';
            win[y - 1 + i][x - 1] = '|';
            win[y - 1 + i][x + k - 2] = '|';
        }

        win[y - 1][x - 1] = '+';
        win[y + k - 2][x - 1] = '+';
        win[y - 1][x + k - 2] = '+';
        win[y + k - 2][x + k - 2] = '+';

        Console.WriteLine(max);
        foreach (char[] row in win)
            Console.WriteLine(String.Join("", row));
    }
}