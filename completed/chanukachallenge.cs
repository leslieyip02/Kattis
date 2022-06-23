using System;

class Program
{
    static void Main(string[] args)
    {
        int p = Convert.ToInt32(Console.ReadLine());
        
        for (int i = 0; i < p; i++)
        {
            int k, n;
            string[] l = Console.ReadLine().Split(" ");
            k = Convert.ToInt32(l[0]);
            n = Convert.ToInt32(l[1]);
            int x = 0;
            for (int j = 2; j <= n + 1 ; j++)
            {
                x += j;
            }
            Console.WriteLine($"{k} {x}");
        }
    }
}