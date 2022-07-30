using System;

class Program
{
    static bool isSorted(byte[] p)
    {
        return (p[0] < p[1] && p[1] < p[2] &&
            p[2] < p[3] && p[3] < p[4]);
    }

    static void Main(String[] args)
    {
        byte[] p = Array.ConvertAll(Console.ReadLine().Split(" "), Convert.ToByte);
        while (!isSorted(p))
        {            
            for (int i = 0; i < 4; i++)
            {
                if (p[i] > p[i + 1])
                {
                    byte tmp = p[i];
                    p[i] = p[i + 1];
                    p[i + 1] = tmp;

                    Console.WriteLine(String.Join(" ", p));
                }
            }
        }
    }
}