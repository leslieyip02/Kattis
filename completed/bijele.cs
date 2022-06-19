using System;

namespace Solution
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] pieces = Console.ReadLine().Split(" ");
            Console.Write(1 - Convert.ToInt32(pieces[0]) + " ");
            Console.Write(1 - Convert.ToInt32(pieces[1]) + " ");
            Console.Write(2 - Convert.ToInt32(pieces[2]) + " ");
            Console.Write(2 - Convert.ToInt32(pieces[3]) + " ");
            Console.Write(2 - Convert.ToInt32(pieces[4]) + " ");
            Console.Write(8 - Convert.ToInt32(pieces[5]) + " ");
        }
    }
}