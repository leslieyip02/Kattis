using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        while (n != 0)
        {
            bool[,] grid = new bool[500, 500];
            int area = 0;
            for (int i = 0; i < n; i++)
            {
                int[] c = Array.ConvertAll(Console.ReadLine().Split(" "), Convert.ToInt32);
                for (int x = c[0]; x < c[2]; x++)
                {
                    for (int y = c[1]; y < c[3]; y++)
                    {
                        if (!grid[y, x])
                        {
                            area++;
                            grid[y, x] = true;
                        }
                    }
                }
            }
            
            Console.WriteLine(area);
            n = Convert.ToInt32(Console.ReadLine());
        }
    }
}