using System;

namespace Solution
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine((double) 100 / a);
            Console.WriteLine((double) 100 / (100 - a));
        }
    }
}