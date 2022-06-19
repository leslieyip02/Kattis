using System;

namespace Solution
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(" ");
            double a = Convert.ToInt32(input[0]);
            double i = Convert.ToInt32(input[1]);

            double citations = 1;
            while (Math.Ceiling(citations / a) < i)
                citations++;

            Console.WriteLine(citations);
        }
    }
}