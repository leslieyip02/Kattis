using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static int Points(int cw, int cmax)
    {
        return 8 + (int) Math.Ceiling((40.0 * (cw - 4)) / (cmax - 4));
    }

    static int Width(int t, int p)
    {
        return (int) Math.Ceiling((9.0 / 16.0) * t * p);
    }

    static void Main(string[] args)
    {
        string[] ln = Console.ReadLine().Split(' ');
        int w = Convert.ToInt32(ln[0]);
        int n = Convert.ToInt32(ln[1]);

        int t = 1;
        while (w != 0 || n != 0)
        {
            string[] words = new string[n];
            int[] c = new int[n];
            int[] p = new int[n];
            int cmax = 0;

            for (int i = 0; i < n; i++)
            {
                ln = Console.ReadLine().Split(' ');
                words[i] = ln[0];
                c[i] = Convert.ToInt32(ln[1]);
                cmax = Math.Max(c[i], cmax);            
            }

            for (int i = 0; i < n; i++)
            {
                p[i] = Points(c[i], cmax);
            }

            int h = 0;
            int x = (int) Width(words[0].Length, p[0]);
            int y = p[0];
            
            for (int i = 1; i < n; i++)
            {
                int z = (int) Math.Ceiling((9.0 / 16.0) * words[i].Length * p[i]);
                
                if (x + z + 10 > w)
                {
                    h += y;
                    x = z;
                    y = p[i];
                }
                else
                {
                    x += z + 10;
                    y = Math.Max(p[i], y);
                }
            }

            h += y;

            Console.WriteLine($"CLOUD {t++}: {h}");

            ln = Console.ReadLine().Split(' ');
            w = Convert.ToInt32(ln[0]);
            n = Convert.ToInt32(ln[1]);
        }
    }
}