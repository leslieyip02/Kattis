using System;

class Program
{
    static void Main(string[] args)
    {
        int x = Convert.ToInt32(Console.ReadLine());
        int n = Convert.ToInt32(Console.ReadLine());

        int p;
        int a = 0;
        for (int i = 0; i < n; i++)
        {
            p = Convert.ToInt32(Console.ReadLine());
            a = Math.Max(a + x - p,0);
        }
        Console.WriteLine(a + x);
    }
}