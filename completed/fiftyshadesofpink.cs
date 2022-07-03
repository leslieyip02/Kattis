using System;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            string color = Console.ReadLine();
            if (color.Contains("pink", StringComparison.OrdinalIgnoreCase) ||
                color.Contains("rose", StringComparison.OrdinalIgnoreCase))
                x++;
        }

        if (x == 0)
            Console.WriteLine("I must watch Star Wars with my daughter");
        else
            Console.WriteLine(x);
    }
}