using System;

class Program
{
    static void Main(string[] args)
    {
        string[] line = Console.ReadLine().Split("()");
        Console.WriteLine(line[0].Length == line[1].Length ? "correct" : "fix");
    }
}