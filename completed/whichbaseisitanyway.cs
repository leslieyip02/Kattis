using System;

class Program
{
    static void Main(string[] args)
    {
        int p = Convert.ToInt32(Console.ReadLine());
        while (p-- > 0)
        {
            string[] d = Console.ReadLine().Split(' ');
            int k = Convert.ToInt32(d[0]);
            string n = d[1];

            long oct = 0;
            long hex = 0;
            for (int i = 0; i < n.Length; i++)
            {
                oct += (long) Math.Pow(8, i) * (long) (n[n.Length - 1 - i] - '0');
                hex += (long) Math.Pow(16, i) * (long) (n[n.Length - 1 - i] - '0');
            }

            if (n.Contains('8') || n.Contains('9'))
                oct = 0;

            Console.WriteLine($"{k} {oct} {Convert.ToInt32(n)} {hex}");
        }
    }
}
