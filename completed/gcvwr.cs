using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        int[] nums = Array.ConvertAll(Console.ReadLine().Split(" "), Convert.ToInt32);
        int g = nums[0];
        int t = nums[1];
        int n = nums[2];

        double c = (g - t) * 0.9;
        c -= Array.ConvertAll(Console.ReadLine().Split(" "), Convert.ToInt32).Sum();
        Console.WriteLine((int) c);
    }
}