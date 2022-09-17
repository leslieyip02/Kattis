using System;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        int[] x = Array.ConvertAll(Console.ReadLine().Split(' '), Convert.ToInt32);

        int k = 0;
        bool increasing = false;
        while (k < n / 2 && !increasing)
        {
            k++;
            increasing = true;
            int previous = x[k - 1];
            for (int i = 2 * k - 1; i < n; i += k)
            {
                if (x[i] <= previous)
                {
                    increasing = false;
                    break;
                }

                previous = x[i];
            }
        }

        if (increasing)
            Console.WriteLine(k);
        else
            Console.WriteLine("ABORT!");
    }
}