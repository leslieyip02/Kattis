using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        char[] l = Console.ReadLine().ToCharArray();

        Stack<char> b = new Stack<char>();

        for (int i = 0; i < n; i++)
        {
            if (l[i] == ' ')
                continue;

            if (l[i] == '(' ||
                l[i] == '[' ||
                l[i] == '{')
                b.Push(l[i]);

            if (l[i] == ')')
            {
                if (b.Count == 0 || b.Pop() != '(')
                {
                    Console.WriteLine($") {i}");
                    return;
                }                
            }
            else if (l[i] == ']')
            {
                if (b.Count == 0 || b.Pop() != '[')
                {
                    Console.WriteLine($"] {i}");
                    return;
                }                
            }
            else if (l[i] == '}')
            {
                if (b.Count == 0 || b.Pop() != '{')
                {
                    Console.WriteLine($"}} {i}");
                    return;
                }                
            }
        }

        Console.WriteLine("ok so far");   
    }
}
