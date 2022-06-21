using System;

namespace Solution
{
    class Program
    {
        static void Main(string[] args)
        {
            int numCases = Convert.ToInt32(Console.ReadLine());
            for (int currentCase = 0; currentCase < numCases; currentCase++)
            {
                string[] testCase = Console.ReadLine().Split(" ");
                
                long n = Convert.ToInt64(testCase[0]);
                
                // return 1 for size 1
                if (n == 1)
                {
                    Console.WriteLine(1);
                    continue;
                }

                long x = Convert.ToInt64(testCase[1]);
                long y = Convert.ToInt64(testCase[2]);
                long w = Convert.ToInt64(testCase[3]);
                long h = Convert.ToInt64(testCase[4]);

                for (int j = 0; j < h; j++)
                {
                    for (int i = 0; i < w; i++)
                    {
                        long currentX = x + i;
                        long currentY = y + j;

                        // keep track of which quadrant the current position is in
                        bool rightHalf, bottomHalf;
                        bool flip = false;

                        // keep downsizing by a factor of 2
                        for (long k = n; k > 1; k /= 2)
                        {
                            // check quadrant based on current context
                            rightHalf = (double) currentX / k >= 0.5;
                            bottomHalf = (double) currentY / k >= 0.5;

                            // need to flip if negative quadrant
                            if (rightHalf && bottomHalf)
                                flip = flip ? false : true;

                            // update position relative to current quadrant for next iteration
                            currentX -= rightHalf ? k / 2 : 0;                                
                            currentY -= bottomHalf ? k / 2 : 0;                                
                        }

                        Console.Write($"{(flip ? -1 : 1)} ");
                    }
                    Console.Write("\n");
                }
            }
        }
    }
}