using System;
using System.Linq;

namespace Solution
{
    public class Person
    {
        public string name;
        public int[] mods;

        public Person(string name, string[] labels)
        {
            // keep the name and discard the colon
            this.name = name.Remove(name.Length - 1, 1);

            mods = new int[labels.Length];
            for (int i = 0; i < labels.Length; i++)
            {
                // store int values for modifiers
                // 1 for upper, 0 for middle, -1 for lower
                if (labels[i] == "upper")
                    mods[i] = 1;
                else if (labels[i] == "lower")
                    mods[i] = -1;
            }
        }

        public int CompareTo(Person that)
        {
            int this_len = this.mods.Length;
            int that_len = that.mods.Length;
            // loop through both people's modifiers from the back
            int len = Math.Max(this.mods.Length, that.mods.Length);
            for (int i = 1 ; i <= len; i++)
            {
                int this_val = (this_len - i < 0) ? 0 : this.mods[this_len - i];
                int that_val = (that_len - i < 0) ? 0 : that.mods[that_len - i];

                // return 1 if this is greater, -1 if smaller
                if (this_val > that_val)
                    return 1;
                else if (this_val < that_val)
                    return -1;
            }

            // if equal value, order by name
            return string.Compare(that.name, this.name);
        }
    }

    public class Program
    {
        public static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            for (int x = 0; x < t; x++)
            {
                int n = Convert.ToInt32(Console.ReadLine());
                Person[] people = new Person[n];
                for (int i = 0; i < n; i++)
                {
                    // read description of each person and create a new Person object
                    string[] desc = Console.ReadLine().Split(" ");
                    Person current_person = new Person(desc[0], desc[1].Split("-"));
                    people[i] = current_person;
                }

                // sort by ascending name and descending class value
                people = people.OrderBy(p => p.name).ToArray();
                for (int i = 0; i < n - 1; i++)
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if (people[i].CompareTo(people[j]) == -1)
                        {
                            // swap if people[j] is classier than people[i]
                            Person tmp = people[i];
                            people[i] = people[j];
                            people[j] = tmp;
                        }
                    }
                }

                for (int i = 0; i < n; i++)
                {
                    Console.WriteLine(people[i].name);
                }
                Console.WriteLine("==============================");
            }
        }
    }
}