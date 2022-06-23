using System;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        int p = 2;
        for (int i = 0; i < n; i++)
            p += (p- 1);
        Console.WriteLine(p * p);
    }
}