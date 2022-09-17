using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int p = Convert.ToInt32(Console.ReadLine());
        while (p-- > 0)
        {
            int[] ln = Array.ConvertAll(Console.ReadLine().Split(' '), Convert.ToInt32);

            int s = 0;
            List<int> c = new List<int>();
            for (int i = 1; i <= 20; i++)
            {
                int j;
                for (j = 0; j < c.Count; j++)
                    if (c[j] > ln[i])
                        break;

                s += c.Count - j;
                c.Insert(j, ln[i]);
            }
            
            Console.WriteLine($"{ln[0]} {s}");
        }
    }
}