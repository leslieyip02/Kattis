using System;

class Program
{
    static void Main(string[] args)
    {
        char[] q = Console.ReadLine().ToCharArray();
        
        bool up1, up2, up3;
        up1 = up2 = up3 = q[0] == 'U';
        
        int a1, a2, a3;
        a1 = a2 = a3 = 0;

        for (int i = 1; i < q.Length; i++)
        {
            if (up1 && q[i] == 'D')
            {
                a1++;
                up1 = false;
            }

            if (!up2 && q[i] == 'U')
            {
                a2++;
                up2 = true;
            }

            if (!up1)
            {
                a1++;
                up1 = true;
            }
            
            if (up2)
            {
                a2++;
                up2 = false;
            }
            
            if ((up3 && q[i] == 'D') ||
                (!up3 && q[i] == 'U'))
            {
                a3++;
                up3 = !up3;
            }
        }
        
        Console.WriteLine(a1);
        Console.WriteLine(a2);
        Console.WriteLine(a3);
    }
}