using System;

namespace Solution
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] names = Console.ReadLine().Split("-");
            foreach (string name in names)
                Console.Write(name[0]);
            Console.Write("\n");
        }
    }
}