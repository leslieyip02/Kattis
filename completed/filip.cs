using System;

class Program
{
    static void Main(string[] args)
    {
        char[] x = Console.ReadLine().ToCharArray();
        Array.Reverse(x);
        string[] y = (new string(x)).Split(" ");
        int a = Convert.ToInt32(y[0]);
        int b = Convert.ToInt32(y[1]);
        Console.WriteLine(a > b ? a : b);
    }
}