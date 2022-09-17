using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static bool IsVowel(char c)
    {
        char[] vowels = { 'a', 'e', 'i', 'o', 'u' };
        return vowels.Contains(c);   
    }

    static bool IsNonConsecutive(List<char> name)
    {
        int consecutive = 0;

        foreach (char c in name)
        {
            if (IsVowel(c))
                consecutive = consecutive > 0 ? consecutive + 1 : 1;
            else
                consecutive = consecutive > 0 ? -1 : consecutive - 1;

            if (consecutive >= 3 || consecutive <= -3)
                return false;
        }

        return true;
    }

    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());

        List<char> name = new List<char> { 'a', 'a', 'a' };
        while (n-- > 0)
        {
            do
            {
                if (name.All(c => c == 'z'))
                {
                    name = name.Select(c => c = 'a').ToList();
                    name.Add('a');
                }

                for (int i = name.Count - 1; i >= 0; i--)
                {
                    if (name[i] != 'z')
                    {
                        name[i] = (char) ((int) name[i] + 1);
                        break;
                    }
                    else
                    {
                        name[i] = 'a';
                    }
                }
            }
            while (!IsNonConsecutive(name));

            Console.WriteLine(String.Join("", name));
        }
    }
}