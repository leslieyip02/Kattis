using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), Convert.ToInt32);
        int n = input[0];
        int m = input[1];

        char[,] students = new char[n, m];
        Dictionary<char, int> hats = new Dictionary<char, int>();

        for (int i = 0; i < n; i++)
        {
            string row = Console.ReadLine();
            for (int j = 0; j < m; j++)
                students[i, j] = row[j];
        }

        int color = 0;
        for (int j = 0; j < m; j++)
        {
            int columnColor = -1;

            for (int i = 0; i < n; i++)
            {
                if (hats.ContainsKey(students[i, j]))
                {
                    columnColor = hats[students[i, j]];
                    break;
                }
            }

            if (columnColor != -1)
            {
                for (int i = 0; i < n; i++)
                    hats[students[i, j]] = columnColor;
            }
            else
            {
                color++;
                for (int i = 0; i < n; i++)
                    hats[students[i, j]] = color;
            }
        }

        Console.WriteLine(color);
    }
}