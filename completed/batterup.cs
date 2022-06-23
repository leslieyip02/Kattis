using System;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        int[] bats = Array.ConvertAll(Console.ReadLine().Trim().Split(' '),Convert.ToInt32);
        int bases = 0;
        foreach (int bat in bats)
        {
            if (bat == -1)
                n--;
            else
                bases += bat;
        }
        Console.WriteLine((double) bases / n);
    }
}