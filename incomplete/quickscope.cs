using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        Stack<Dictionary<string, string>> states = new Stack<Dictionary<string, string>>();
        states.Push(new Dictionary<string, string>());

        while (n-- > 0)
        {
            string[] ln = Console.ReadLine().Split(' ');

            // change block
            if (ln.Length == 1)
            {
                if (ln[0] == "{")
                    states.Push(new Dictionary<string, string>());
                else
                    states.Pop();
            }
            // print variable
            else if (ln.Length == 2)
            {
                string variableType = "";

                foreach (Dictionary<string, string> scope in states)
                {
                    if (scope.ContainsKey(ln[1]))
                    {
                        variableType = scope[ln[1]];
                        break;
                    }
                }

                Console.WriteLine(variableType.Length > 0 ? variableType : "UNDECLARED");
            }
            // declare variable
            else
            {
                if (states.Peek().ContainsKey(ln[1]))
                {
                    Console.WriteLine("MULTIPLE DECLARATION");
                    return;
                }

                states.Peek().Add(ln[1], ln[2]);
            }
        }
    }
}
