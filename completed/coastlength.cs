using System;

class Program
{
    static int n, m;
    static int[][] map;
    static (int, int)[] dirs = {(1, 0), (-1, 0), (0, 1), (0, -1)};

    static void Flood(int x0, int y0)
    {
        if (map[y0][x0] == 0)
        {
            map[y0][x0] = 2;
            
            foreach (var dir in dirs)
            {
                int x1 = x0 + dir.Item1;
                int y1 = y0 + dir.Item2;

                if (0 <= x1 && x1 < m &&
                    0 <= y1 && y1 < n)
                    Flood(x1, y1);
            }
        }
    }

    static void Main(string[] args)
    {
        string[] ln = Console.ReadLine().Split(" ");
        n = Convert.ToInt32(ln[0]);
        m = Convert.ToInt32(ln[1]);

        map = new int[n][];
        for (int i = 0; i < n; i++)
            map[i] = Array.ConvertAll(Console.ReadLine().ToCharArray(),
                c => (int) Char.GetNumericValue(c));

        for (int i = 0; i < m; i++)
        {
            Flood(i, 0);
            Flood(i, n - 1);
        }

        for (int i = 0; i < n; i++)
        {
            Flood(0, i);
            Flood(m - 1, i);
        }

        int l = 0;
        for (int y0 = 0; y0 < n; y0++)
        {
            for (int x0 = 0; x0 < m; x0++)
            {
                if (map[y0][x0] == 1)
                {
                    foreach (var dir in dirs)
                    {
                        int x1 = x0 + dir.Item1;
                        int y1 = y0 + dir.Item2;

                        if (0 <= x1 && x1 < m &&
                            0 <= y1 && y1 < n &&
                            map[y1][x1] == 2)
                            l++;

                        else if (x1 < 0 || x1 >= m ||
                            y1 < 0 || y1 >= n)
                            l++;
                    }
                }
            }
        }

        Console.WriteLine(l);
    }
}