using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        int t = Convert.ToInt32(Console.ReadLine());
        for (int c = 0; c < t; c++)
        {
            string[] a = Console.ReadLine().Split(' ');
            string[] b = Console.ReadLine().Split(' ');
            int sum = Convert.ToInt32(String.Join("", a)) +
                Convert.ToInt32(String.Join("", b));
            foreach (char s in Convert.ToString(sum))
                Console.Write($"{s} ");
            Console.WriteLine();
        }
    }
}