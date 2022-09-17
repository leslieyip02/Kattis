using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(String[] args)
    {
        String[] p = Console.ReadLine().Split(' ');
        int c = Convert.ToInt32(p[0]);
        int n = Convert.ToInt32(p[1]);

        int[] lines = Array.ConvertAll(Console.ReadLine().Split(' '), Convert.ToInt32);
        List<string> errors = new List<string>();
        List<string> correct = new List<string>();

        int last = 1;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            for (; j < n - 1; j++)
                if (lines[j] + 1 != lines[j + 1])
                    break;

            if (j == i)
                errors.Add(lines[i].ToString());
            else
                errors.Add($"{lines[i]}-{lines[j]}");
            
            if (lines[i] - 1 == last)
                correct.Add($"{last}");
            else if (lines[i] > 1)
                correct.Add($"{last}-{lines[i] - 1}");
                
            last = lines[j] + 1;
            i = j;
        }

        if (last != c + 1 && last != c)
            correct.Add($"{last}-{c}");
        else if (last <= c)
            correct.Add($"{last}");

        if (errors.Count == 1)
            Console.WriteLine($"Errors: {errors[0]}");
        else
            Console.WriteLine($"Errors: {String.Join((", "), errors.Take(errors.Count - 1))} and {errors.Last()}");

        if (correct.Count == 1)
            Console.WriteLine($"Correct: {correct[0]}");
        else
            Console.WriteLine($"Correct: {String.Join((", "), correct.Take(correct.Count - 1))} and {correct.Last()}");
    }
}

