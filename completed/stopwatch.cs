using System;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        if (n % 2 == 1)
        {
            Console.WriteLine("still running");
        }
        else
        {
            int t = 0;
            for (int i = 0; i < n; i += 2)
            {
                t -= Convert.ToInt32(Console.ReadLine()) - Convert.ToInt32(Console.ReadLine());
            }
            Console.WriteLine(t);
        }
    }
}