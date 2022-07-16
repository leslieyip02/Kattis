using System;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        while (n != -1)
        {
            bool[][] vertices = new bool[n][];
            for (int i = 0; i < n; i++)
                vertices[i] = Array.ConvertAll(
                    Array.ConvertAll(Console.ReadLine().Split(" "), Convert.ToInt16),
                    Convert.ToBoolean);

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (i == j || i == k || j == k)
                            continue;
                        
                        if (vertices[i][j] && 
                            vertices[i][k] && 
                            vertices[j][k])
                            goto next;
                    }
                }

                Console.Write($"{i} ");

                next:
                    continue;
            }
            Console.WriteLine();

            n = Convert.ToInt32(Console.ReadLine());
        }
    }
}