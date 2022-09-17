using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static HashSet<(int, int, int)> day = new HashSet<(int, int, int)>();

    static void Main(string[] args)
    {
        int starts = 0;

        int n = Convert.ToInt32(Console.ReadLine());
        while (n-- > 0)
        {
            string[][] tokens = Console.ReadLine().Split(' ')
                .Select(token => token.Split(','))
                .ToArray();
            
            List<int>[] jobs = new List<int>[3];
            for (int i = 0; i < 3; i++)
            {
                jobs[i] = new List<int>();
                foreach (string token in tokens[i])
                {
                    if (token == "*")
                    {
                        jobs[i] = Enumerable.Range(0, i == 0 ? 24 : 60).ToList();
                        break;
                    }

                    int[] range = Array.ConvertAll(token.Split('-'), Convert.ToInt32);                    
                    for (int j = range[0]; j <= range[range.Length - 1]; j++)
                        jobs[i].Add(j);
                }
            }

            foreach (int h in jobs[0])
                foreach (int m in jobs[1])
                    foreach (int s in jobs[2])
                        day.Add((h, m, s));

            starts += jobs[0].Count * jobs[1].Count * jobs[2].Count;
        }

        Console.WriteLine($"{day.Count} {starts}");
    }
}