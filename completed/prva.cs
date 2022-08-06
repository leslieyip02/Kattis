using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] line = Console.ReadLine().Split(" ");
        int r = Convert.ToInt32(line[0]);
        int c = Convert.ToInt32(line[1]);

        string shortest = "".PadLeft(Math.Max(r, c) + 1, 'z');
        string[] vertical = new string[c];
        for (int i = 0; i < c; i++)
            vertical[i] = "#";

        for (int i = 0; i < r; i++)
        {
            string row = Console.ReadLine();

            foreach (string word in row.Split("#"))
                if (word.Length >= 2)
                    shortest = String.Compare(word, shortest) == -1 ? word : shortest;

            for (int j = 0; j < c; j++)
            {
                if (vertical[j] == "#")
                    vertical[j] = "";

                if (row[j] == '#')
                {
                    if (vertical[j].Length >= 2)
                        shortest = String.Compare(vertical[j], shortest) == -1 ? vertical[j] : shortest;
                    vertical[j] = "";
                }

                vertical[j] += row[j];
            }
        }

        foreach (string word in vertical)
            if (word.Length >= 2)
                shortest = String.Compare(word, shortest) == -1 ? word : shortest;

        Console.WriteLine(shortest);
    }
}