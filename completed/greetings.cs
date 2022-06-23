using System;

class Program
{
    static void Main(string[] args)
    {
        string hey = Console.ReadLine();
        int e = hey.Length - 2;
        Console.Write("h");
        for (int i = 0; i < e; i++)
            Console.Write("ee");
        Console.Write("y");
    }
}