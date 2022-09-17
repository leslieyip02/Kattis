using System;
using System.Collections.Generic;

class Program
{
    static Dictionary<char, int[]> notes = new Dictionary<char, int[]>
    {
        { 'c', new int[] { 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 } },
        { 'd', new int[] { 0, 1, 1, 1, 0, 0, 1, 1, 1, 0 } },
        { 'e', new int[] { 0, 1, 1, 1, 0, 0, 1, 1, 0, 0 } },
        { 'f', new int[] { 0, 1, 1, 1, 0, 0, 1, 0, 0, 0 } },
        { 'g', new int[] { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 } },
        { 'a', new int[] { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 } },
        { 'b', new int[] { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 } },
        { 'C', new int[] { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 } },
        { 'D', new int[] { 1, 1, 1, 1, 0, 0, 1, 1, 1, 0 } },
        { 'E', new int[] { 1, 1, 1, 1, 0, 0, 1, 1, 0, 0 } },
        { 'F', new int[] { 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 } },
        { 'G', new int[] { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 } },
        { 'A', new int[] { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 } },
        { 'B', new int[] { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 } }
    };

    static void Main(string[] args)
    {
        int t = Convert.ToInt32(Console.ReadLine());
        while (t-- > 0)
        {
            int[] btns = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            int[] presses = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

            char[] song = Console.ReadLine().ToCharArray();
            foreach (char note in song)
            {
                for (int i = 0; i < 10; i++)
                {
                    if (btns[i] == 0 && notes[note][i] == 1)
                    {
                        btns[i] = 1;
                        presses[i]++;
                    }
                    else if (btns[i] == 1 && notes[note][i] == 0)
                    {
                        btns[i] = 0;
                    }
                }
            }

            Console.WriteLine(String.Join(' ', presses));                
        }
    }
}