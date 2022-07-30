using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int t = 1;
        int n = Convert.ToInt32(Console.ReadLine());
        while (n != 0)
        {
            List<string> top = new List<string>();
            List<string> bottom = new List<string>();

            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                    top.Add(Console.ReadLine());
                else
                    bottom.Add(Console.ReadLine());
            }

            Console.WriteLine($"SET {t}");
            foreach (string name in top)
                Console.WriteLine(name);

            bottom.Reverse();
            foreach (string name in bottom)
                Console.WriteLine(name);

            n = Convert.ToInt32(Console.ReadLine());
            t++;
        }
    }
}