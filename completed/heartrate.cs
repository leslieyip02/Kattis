using System;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        for (int i = 0; i < n; i++)
        {
            string[] line = Console.ReadLine().Split(' ');
            int b = Convert.ToInt32(line[0]);
            double p = Convert.ToDouble(line[1]);

            Console.WriteLine($"{ 60 / p * (b - 1) } { 60 / p * b } { 60 / p * (b + 1) }");
        }
    }
}