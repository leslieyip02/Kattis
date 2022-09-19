using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int t = Convert.ToInt32(Console.ReadLine());
        while (t-- > 0)
        {
            Dictionary<string, int> toys = new Dictionary<string, int>();
            
            int n = Convert.ToInt32(Console.ReadLine());
            while (n-- > 0)
            {
                string[] ln = Console.ReadLine().Split(' ');
                if (!toys.ContainsKey(ln[0]))
                    toys[ln[0]] = 0;
                toys[ln[0]] += Convert.ToInt32(ln[1]);
            }
            
            int k = toys.Count;
            toys = toys.OrderBy(toy => toy.Key)
                .OrderByDescending(toy => toy.Value)
                .ToDictionary(toy => toy.Key, toy => toy.Value);
                
            Console.WriteLine(k);
            foreach (KeyValuePair<string, int> toy in toys)
                Console.WriteLine($"{toy.Key} {toy.Value}");
            
        }
    }
}