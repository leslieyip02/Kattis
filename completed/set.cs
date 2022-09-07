using System;
using System.Collections.Generic;

class Program
{
    static bool isSet(string a, string b, string c)
    {
        for (int i = 0; i < 4; i++)
        {
            if ((a[i] == b[i] && a[i] != c[i]) ||
                (a[i] == c[i] && a[i] != b[i]) ||
                (b[i] == c[i] && b[i] != a[i]))
                return false;
        }

        return true;
    }

    static void Main(string[] args)
    {
        List<string> cards = new List<string>();
        for (int i = 0; i < 4; i++)
            cards.AddRange(Console.ReadLine().Split(" "));

        List<(int, int, int)> sets = new List<(int, int, int)>();
        for (int i = 0; i < 10; i++)
            for (int j = i + 1; j < 11; j++)
                for (int k = j + 1; k < 12; k++)
                    if (isSet(cards[i], cards[j], cards[k]))
                        sets.Add(( i + 1, j + 1, k + 1 ));

        if (sets.Count == 0)
            Console.WriteLine("no sets");
        else
            foreach ((int, int, int) set in sets)
                Console.WriteLine($"{set.Item1} {set.Item2} {set.Item3}");
    }
}