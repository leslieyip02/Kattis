using System;
using System.Collections.Generic;

namespace Solution
{
    class Program
    {
        public static void Main(string[] args)
        {
            string[] n_t = Console.ReadLine().Split(' ');
            int n = Convert.ToInt32(n_t[0]);
            int t = Convert.ToInt32(n_t[1]);

            List<int> pots = new List<int>();
            // the window to drink initially is the highest potion duration
            int window = 0;
            for (int i = 0; i < n; i++)
            {
                int x = Convert.ToInt32(Console.ReadLine());
                if (x > window) { window = x; }
                pots.Add(x);
            }
            // sort in ascending order
            pots.Sort();
            
            // skip the last potion as it is assumed to be drunk
            for (int i = n - 2; i >= 0; i--)
            {
                // drinking
                window -= t;
                // shrink window if potion lasts less than the current window
                if (pots[i] < window) { window -= window - pots[i]; }
                if (window <= 0) {
                  Console.WriteLine("NO");
                  return;
                }
            }
            Console.WriteLine("YES");
            return;
        }
    }
}