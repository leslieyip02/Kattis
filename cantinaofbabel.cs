using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    class Speaker
    {
        public string Language { get; set; }
        public int Index { get; set; }
        public bool Drunk { get; set; }
        public List<string> canUnderstand;
        public List<int> canTalkTo = new List<int>();

        public Speaker(IEnumerable<string> languages, int index)
        {
            this.Language = languages.First();
            this.Index = index;
            this.Drunk = false;

            canUnderstand = new List<string>(languages);
        }

        public void TalkTo(Speaker target)
        {
            if (target.Index == this.Index)
                return;

            if (target.canUnderstand.Contains(this.Language))
            {
                this.canTalkTo.Add(target.Index);
            }
        }

        public HashSet<int> GetDrinksAtTheBar(HashSet<int> currentChain)
        {
            if (currentChain.FirstOrDefault() == this.Index)
                return currentChain;

            currentChain.Add(this.Index);

            HashSet<int> longestChain = new HashSet<int>();
            foreach (int i in this.canTalkTo)
            {
                if (currentChain.Skip(1).Contains(i))
                    continue;

                HashSet<int> newChain = speakers[i - 1].GetDrinksAtTheBar(new HashSet<int>(currentChain));
                longestChain.UnionWith(newChain);
            }

            return longestChain;
        }
    }

    static Speaker[] speakers;

    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        speakers = new Speaker[n];

        for (int i = 0; i < n; i++)
            speakers[i] = new Speaker(Console.ReadLine().Split(" ").Skip(1), i + 1);

        foreach (Speaker s1 in speakers)
            foreach (Speaker s2 in speakers)
                s1.TalkTo(s2);

        HashSet<int> maxGroup = new HashSet<int>();
        foreach (Speaker s in speakers)
        {
            if (s.Drunk)
                continue;

            HashSet<int> group = s.GetDrinksAtTheBar(new HashSet<int>());
            foreach (int g in group)
                speakers[g - 1].Drunk = true;

            if (maxGroup.Intersect(group).Count() > 0)
                maxGroup.UnionWith(group);
            else if (group.Count() > maxGroup.Count())
                maxGroup = group;
        }

        Console.WriteLine(maxGroup.Count() == 0 ? n - 1 : n - maxGroup.Count());
    }
}