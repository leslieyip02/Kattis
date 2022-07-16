using System;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        for (int i = 0; i < n; i++)
        {
            string instruction = Console.ReadLine();
            if (instruction.StartsWith("Simon says"))
            {
                Console.WriteLine(instruction.Substring(11));
            }
        }
    }
}