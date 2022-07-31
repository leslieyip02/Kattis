using System;
using System.Linq;

class Program
{
    public static int m, n;
    public static bool[][] sky;
    public static void Flood(int i, int j)
    {
        if (!sky[i][j])
            return;

        sky[i][j] = false;

        if (i - 1 >= 0 && sky[i - 1][j])
            Flood(i - 1, j);
        if (i + 1 < m && sky[i + 1][j])
            Flood(i + 1, j);
        if (j - 1 >= 0 && sky[i][j - 1])
            Flood(i, j - 1);
        if (j + 1 < n && sky[i][j + 1])
            Flood(i, j + 1);
    }

    public static void Main(String[] args)
    {
        int t = 1;
        while (true)
        {
            try
            {
                int[] p = Array.ConvertAll(Console.ReadLine().Split(" "), Convert.ToInt32);
                m = p[0];
                n = p[1];

                sky = new bool[m][];
                for (int i = 0; i < m; i++)
                {
                    sky[i] = Console.ReadLine()
                        .ToCharArray()
                        .Select(x => x == '-')
                        .ToArray();
                }

                int stars = 0;
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (sky[i][j])
                        {
                            stars++;
                            Flood(i, j);
                        }

                    }
                }
                Console.WriteLine($"Case {t}: {stars}");
                t++;
            }
            catch
            {
                break;
            }
        }
    }
}