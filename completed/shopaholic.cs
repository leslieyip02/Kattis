using System;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        int[] p = Array.ConvertAll(Console.ReadLine().Split(' '), Convert.ToInt32);
        Array.Sort(p);
        Array.Reverse(p);
        
        ulong d = 0;
        for (int i = 2; i < n; i += 3)
            d += (ulong) p[i];

        Console.WriteLine(d);
    }
}