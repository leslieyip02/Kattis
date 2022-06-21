using System;

namespace Solution
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            
            double x = 0;
            for (int i = 0; i < n; i++)
            {
                string p = Console.ReadLine();
                double power = Char.GetNumericValue(p[p.Length - 1]);
                x += Math.Pow(Convert.ToInt32(p.Remove(p.Length - 1, 1)), power);
            }

            Console.WriteLine(x);
        }
    }
}