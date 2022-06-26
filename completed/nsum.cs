using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        int[] nums = Array.ConvertAll(Console.ReadLine().Split(" "), Convert.ToInt32);
        Console.WriteLine(nums.Sum());
    }
}