using System;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine(n % 2 == 1 ? "first" : "second");
    }
}
