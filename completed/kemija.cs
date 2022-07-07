using System;

class Program
{
    static void Main(string[] args)
    {
        string[] words = Console.ReadLine().Split(" ");
        foreach (string word in words)
        {
            for (int i = 0; i < word.Length; i++)
            {
                Console.Write(word[i]);
                if (word[i] == 'a' ||
                    word[i] == 'e' ||
                    word[i] == 'i' ||
                    word[i] == 'o' ||
                    word[i] == 'u')
                    i += 2;
            }
            Console.Write(" ");
        }
    }
}