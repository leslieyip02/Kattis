using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        for (int i = 0; i < n; i++)
        {
            string line = Console.ReadLine();
            if (line.Contains("="))
                Console.WriteLine("skipped");
            else
                Console.WriteLine(Array.ConvertAll(line.Split("+"), Convert.ToInt32).Sum());
        }
    }
}