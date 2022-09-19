using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());

        List<string> names = new List<string>();
        int shortest = 50;
        for (int i = 0; i < n; i++)
        {
            string s = Console.ReadLine();
            if (s.Length >= 5 &&
                s.ToCharArray().Distinct().Count() == s.Length)
            {
                shortest = Math.Min(s.Length, shortest);
                names.Add(s);
            }
        }

        names = names.FindAll(s => s.Length == shortest);
        names.Sort();
        
        Console.WriteLine(names.Count > 0 ? names.Last() : "neibb!");
    }
}