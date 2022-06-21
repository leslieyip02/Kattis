using System;

namespace Solution
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            string[] temps = Console.ReadLine().Split(" ");
            
            int belowZero = 0;
            for (int i = 0; i < n; i++)
                if (Convert.ToInt32(temps[i]) < 0)
                    belowZero++;

            Console.WriteLine(belowZero);
        }
    }
}