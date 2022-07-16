using System;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        for (int i = 0; i < n; i++)
        {
            bool eligible = false;
            string[] input = Console.ReadLine().Split(" ");

            if (Convert.ToInt32(input[1].Split("/")[0]) >= 2010)
                eligible = true;

            if (Convert.ToInt32(input[2].Split("/")[0]) >= 1991)
                eligible = true;

            if (!eligible)
                if (Convert.ToInt32(input[3]) > 40)
                    Console.WriteLine($"{input[0]} ineligible");
                else
                    Console.WriteLine($"{input[0]} coach petitions");
            else
                Console.WriteLine($"{input[0]} eligible");
        }
    }
}