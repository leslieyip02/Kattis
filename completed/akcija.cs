using System;
using System.Collections.Generic;

namespace Solution
{
  class Program
  {
    public static void Main(string[] args)
    {
      int n = Convert.ToInt32(Console.ReadLine());
      List<int> books = new List<int>();
      for (int i = 0; i < n; i++)
      {
        int c = Convert.ToInt32(Console.ReadLine());
        books.Add(c);
      }
      books.Sort();

      int cost = 0;
      int counter = 0;
      for (int i = n - 1; i >= 0; i--)
      {
        if (counter != 2)
        {
          cost += books[i];
          counter++;
        }
        else
        {
          counter = 0;
        }
      }
      Console.WriteLine(cost);
      return;
    }
  }
}