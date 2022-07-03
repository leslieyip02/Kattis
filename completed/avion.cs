using System;

class Program
{
    static void Main(string[] args)
    {
        bool found = false;
        for (int i = 1; i <= 5; i++)
        {
            string code = Console.ReadLine();
            if (code.Contains("FBI"))
            {
                Console.Write($"{i} ");
                found = true;
            }
        }
        
        if (!found)
            Console.WriteLine("HE GOT AWAY!");
    }
}