using System;

class Program
{
    static void Main(String[] args)
    {
        String mc = Console.ReadLine();

        int i = 0;
        int n = 0;
        foreach (char c in mc)
        {
            if (Char.IsUpper(c))
            {
                n += (4 - i) % 4;
                i = 0;
            }
                    
            i = (i + 1) % 4;
        }

        Console.WriteLine(n);
    }
}