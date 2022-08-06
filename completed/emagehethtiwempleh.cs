using System;

class Program
{
    public static void Main(String[] args)
    {
        char[,] board = new char[8, 8];
        for (int j = 0; j < 8; j++)
            for (int i = 0; i < 8; i++)
                board[i, j] = (i + j) % 2 == 0 ? '.' : ':';

        String[] white = Console.ReadLine().Split(" ");
        String[] black = Console.ReadLine().Split(" ");

        try
        {
            foreach (String piece in white[1].Split(","))
            {
                if (piece.Length == 3)
                {
                    int x = (int) piece[1] - 97;
                    int y = 8 -((int) piece[2] - '0');
                    board[x, y] = piece[0];
                }
                else
                {
                    int x = (int) piece[0] - 97;
                    int y = 8 -((int) piece[1] - '0');
                    board[x, y] = 'P';
                }
            }
        }
        catch {}

        try
        {
            foreach (String piece in black[1].Split(","))
            {
                if (piece.Length == 3)
                {
                    int x = (int) piece[1] - 97;
                    int y = 8 -((int) piece[2] - '0');
                    board[x, y] = Char.ToLower(piece[0]);
                }
                else
                {
                    int x = (int) piece[0] - 97;
                    int y = 8 -((int) piece[1] - '0');
                    board[x, y] = 'p';
                }
            }
        }
        catch {}

        String row = "";
        for (int i = 0; i < 8; i++)
            row += "+---";
        row += "+";

        for (int j = 0; j < 8; j++)
        {
            Console.WriteLine(row);

            for (int i = 0; i < 8; i++)
            {
                if ((i + j) % 2 == 0)
                    Console.Write($"|.{board[i, j]}.");
                else 
                    Console.Write($"|:{board[i, j]}:");
            }
            Console.WriteLine("|");
        }
        Console.WriteLine(row);
    } 
}