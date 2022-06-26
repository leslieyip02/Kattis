using System;

class Program
{
    static void Main(string[] args)
    {
        string[] psets = Console.ReadLine().Split(';');
        int n = 0;
        foreach (string p in psets)
        {
            string[] r = p.Split('-');
            if (r.Length > 1)
                n += Convert.ToInt32(r[1]) - Convert.ToInt32(r[0]) + 1;
            else
                n++;
        }
        Console.WriteLine(n);
    }
}