using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        char[] street = Console.ReadLine().ToCharArray();

        // number of crossings for each side
        int n = 0; 
        int s = 1;
        for (int i = 0; i < street.Length; i++)
        {
            if (street[i] == 'N' || street[i] == 'B')
                n++;

            if (street[i] == 'S' || street[i] == 'B')
                s++;

            int c = s;
            s = Math.Min(c, n + 1);
            n = Math.Min(n, c + 1);
        }

        Console.WriteLine(n);
    }
}