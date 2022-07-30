using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static String[] namelist;
    static Dictionary<string, string> characters = new Dictionary<string, string>();
    static Dictionary<string, List<string>> understands = new Dictionary<string, List<string>>();
    static Stack<int> stack = new Stack<int>();
    static int[] pre;
    static int[] low;
    static int[] scc;
    static int c1 = 0;
    static int c2 = 0;
    static int max = 0;

    static void Dfs(int i)
    {
        stack.Push(i);
        pre[i] = c1;
        low[i] = pre[i];
        c1++;

        foreach (string character in understands[characters[namelist[i]]])
        {
            int j = Array.IndexOf(namelist, character);
            if (pre[j] != -1)
            {
                if (scc[j] == -1)
                {
                    low[i] = Math.Min(low[i], pre[j]);
                }
                continue;
            }

            Dfs(j);
            low[i] = Math.Min(low[i], low[j]);
        }

        if (low[i] == pre[i])
        {
            int w = -1;
            int ppl = 0;
            while (w != i)
            {
                ppl++;
                w = stack.Pop();
                scc[w] = c2;
            }
            max = Math.Max(max, ppl);
            c2++;
        }
    }

    static void Main(String[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        namelist = new String[n];
        for (int i = 0; i < n; i++)
        {
            String[] line = Console.ReadLine().Split(" ");
            String name = line[0];
            namelist[i] = name;
            String motherTongue = line[1];
            characters.Add(name, motherTongue);
            for (int l = 1; l < line.Length; l++)
            {
                String lang = line[l];
                if (!understands.ContainsKey(lang))
                    understands.Add(lang, new List<string>());
                understands[lang].Add(name);
            }
        }

        pre = new int[n];
        low = new int[n];
        scc = new int[n];
        Array.Fill(pre, -1);
        Array.Fill(low, -1);
        Array.Fill(scc, -1);

        for (int i = 0; i < n; i++)
        {
            if (scc[i] == -1)
                Dfs(i);
        }
        Console.WriteLine(n - max);
    }
}