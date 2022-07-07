using System;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        int[] rings = Array.ConvertAll(Console.ReadLine().Split(" "), Convert.ToInt32);
        for (int i = 1; i < n; i++)
        {
            int hcf = 1;
            for (int f = 2; f <= Math.Min(rings[0], rings[i]); f++)
                if (rings[0] % f == 0 && rings[i] % f == 0)
                    hcf = f;

            Console.WriteLine($"{(rings[0] / hcf)}/{(rings[i] / hcf)}");
        }
    }
}