using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        HashSet<int> days = new HashSet<int>();

        for (int i = 0; i < n; i++)
        {
            int[] range = Array.ConvertAll(Console.ReadLine().Split(" "), Convert.ToInt32);
            days.UnionWith(Enumerable.Range(range[0], range[1] - range[0] + 1));
        }

        Console.WriteLine(days.Count());
    }
}