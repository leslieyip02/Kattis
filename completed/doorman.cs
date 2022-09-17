using System;

class Program
{
    static void Swap(ref char[] q, int i, int j)
    {
        char tmp = q[i];
        q[i] = q[j];
        q[j] = tmp;
    }

    static void Main(string[] args)
    {
        int x = Convert.ToInt32(Console.ReadLine());

        int m = 0, w = 0;
        char[] q = Console.ReadLine().ToCharArray();

        for (int i = 0; i < q.Length; i++)
        {
            if (m - w == x && q[i] != 'W')
            {
                if (q[i + 1] == 'W')
                    Swap(ref q, i, i + 1);
                else
                    break;
            }
            
            if (w - m == x && q[i] != 'M')
            {
                if (q[i + 1] == 'M')
                    Swap(ref q, i, i + 1);
                else
                    break;
            }

            if (q[i] == 'M')
                m++;
            else
                w++;
        }

        Console.WriteLine(m + w);
    }
}
