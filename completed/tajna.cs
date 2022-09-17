using System;

class Program
{
    static void Main(string[] args)
    {
        string msg = Console.ReadLine();

        int r = 1;
        int c = msg.Length;
        for (int i = (int) Math.Sqrt(msg.Length); i >= 2; i--)
        {
            if (msg.Length % i == 0)
            {
                r = i;
                c = msg.Length / i;
                break;
            }
        }

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                Console.Write(msg[i + j * r]);
        Console.WriteLine();
    }
}