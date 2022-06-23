using System;

namespace Solution
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = Convert.ToInt16(Console.ReadLine());
            string feedback;
            int max = 11, min = -1;

            while (num != 0)
            {
                feedback = Console.ReadLine();
                if (feedback == "right on")
                {
                    Console.WriteLine((num < max && num > min) ?
                        "Stan may be honest" : "Stan is dishonest");
                    max = 11;
                    min = -1;
                }

                if (feedback == "too high")
                    max = Math.Min(num, max);
                else if (feedback == "too low")
                    min = Math.Max(num, min);

                num = Convert.ToInt16(Console.ReadLine());
            }
        }
    }
}