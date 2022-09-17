using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static int[] Input()
    {
        return Array.ConvertAll(Console.ReadLine().Split(' '), Convert.ToInt32);
    }

    static int n;
    static int[,] intersections;
    static int[,] timeAtEach;
    static int[] distances;
    static bool[] visited;

    static int ClosestIntersection()
    {
        int shortest = 1000000000;
        int closestIndex = -1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && distances[i] < shortest)
            {
                shortest = distances[i];
                closestIndex = i;
            }
        }

        return closestIndex;
    }

    static int Block(int i, int j)
    {
        // check if blocking takes more t
        return Math.Max(timeAtEach[i, j] + intersections[i, j], distances[i])
            + intersections[i, j];
    }

    static void Main(string[] args)
    {
        int m, a, b, k, g;

        int[] ln = Input();
        n = ln[0];
        m = ln[1];

        ln = Input();
        a = ln[0] - 1;
        b = ln[1] - 1;
        k = ln[2];
        g = ln[3];

        intersections = new int[n, n];
        timeAtEach = new int[n, n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                intersections[i, j] = timeAtEach[i, j] = 1000000000;

        int[] georged = Input()
            .Select(x => x - 1)
            .ToArray();

        for (int i = 0; i < m; i++)
        {
            ln = Input();
            intersections[ln[0] - 1, ln[1] - 1] = ln[2];
            intersections[ln[1] - 1, ln[0] - 1] = ln[2];
        }

        for (int i = 0, t = 0; i < g - 1; i++)
        {
            timeAtEach[georged[i], georged[i + 1]] = t;
            timeAtEach[georged[i + 1], georged[i]] = t;
            t += intersections[georged[i], georged[i + 1]];
        }

        distances = Enumerable.Repeat(1000000000, n).ToArray();
        visited = new bool[n];

        distances[a] = k;
        for (int i = 0; i < n; i++)
        {
            int c = ClosestIntersection();
            visited[c] = true;

            for (int j = 0; j < n; j++)
            {
                // normal dijkstra
                if (distances[c] < timeAtEach[c, j])
                {
                    distances[j] = Math.Min(distances[j], distances[c] + intersections[c, j]);
                }
                // blocked
                else
                {
                    distances[j] = Math.Min(distances[j], Block(c, j));
                }
            }
        }

        Console.WriteLine(distances[b] - k);
    }
}
