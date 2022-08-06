using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    public static void Main(String[] args)
    {
        char[][] board = new char[8][];
        for (int i = 0; i < 8; i++)
        {
            Console.ReadLine();
            board[i] = Console.ReadLine().Split("|")
                .Where(s => s.Length > 0)
                .Select(s => s[1])
                .ToArray();
        }

        Dictionary<char, List<String>> white = new Dictionary<char, List<string>>();
        Dictionary<char, List<String>> black = new Dictionary<char, List<string>>();
        for (int j = 0; j < 8; j++)
        {
            Dictionary<char, List<String>> row = new Dictionary<char, List<string>>();
            for (int i = 0; i < 8; i++)
            {
                char pieceType = board[j][i];
                if (pieceType == '.' || pieceType == ':')
                    continue;

                String piece = Char.ToUpper(pieceType) + "";
                if (piece == "P")
                    piece = "";
                piece += (char) (i + 97);
                piece += 8 - j;

                if (!row.ContainsKey(pieceType))
                    row.Add(pieceType, new List<String>());
                row[pieceType].Add(piece);
            }

            foreach (KeyValuePair<char, List<String>> pieces in row)
            {
                if (Char.IsUpper(pieces.Key))
                {
                    if (!white.ContainsKey(pieces.Key))
                        white.Add(pieces.Key, new List<String>());
                    white[pieces.Key].InsertRange(0, pieces.Value);
                }
                else
                {
                    if (!black.ContainsKey(pieces.Key))
                        black.Add(pieces.Key, new List<String>());
                    black[pieces.Key].AddRange(pieces.Value);
                }
            }
        }

        char[] pieceOrder = { 'K', 'Q', 'R', 'B', 'N', 'P' };
        List<String> sortedWhite = new List<String>();
        foreach (char piece in pieceOrder)
            if (white.ContainsKey(piece))
                sortedWhite.AddRange(white[piece]);
        Console.WriteLine($"White: {String.Join(",", sortedWhite)}");

        List<String> sortedBlack = new List<String>();
        foreach (char piece in pieceOrder)
            if (black.ContainsKey(Char.ToLower(piece)))
                sortedBlack.AddRange(black[Char.ToLower(piece)]);
        Console.WriteLine($"Black: {String.Join(",", sortedBlack)}");
    }
}
