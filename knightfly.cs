using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static int tx, ty;
    static Dictionary<int, List<int>> rows = new Dictionary<int, List<int>>();
    static Dictionary<int, List<int>> cols = new Dictionary<int, List<int>>();
    static Dictionary<(int x, int y), int> cells = new Dictionary<(int x, int y), int>();

    static List<Tuple<int, int>> fly_from(int x1, int y1)
    {
        List<Tuple<int, int>> new_starters = new List<Tuple<int, int>>();

        if (cells[(x1, y1)] > 0)
        {
            for (int o1 = -2; o1 <= 2; o1 += 4)
            {
                int x2_i = rows[y1].BinarySearch(x1) + o1;
                if (x2_i >= 0 && x2_i < rows[y1].Count())
                {
                    int x2 = rows[y1][x2_i];
                    for (int o2 = -1; o2 <= 1; o2 += 2)
                    {
                        int y2_i = cols[x2].BinarySearch(y1) + o2;
                        if (y2_i >= 0 && y2_i  < cols[x2].Count())
                        {
                            int y2 = cols[x2][y2_i];
                            if (cells[(x2, y2)] == 0)
                            {
                                cells[(x2, y2)] = cells[(x1, y1)] + 1;
                                new_starters.Add(new Tuple<int, int>(x2, y2));
                            }
                            else if (cells[(x2, y2)] < 0)
                            {
                                cells[(tx, ty)] = cells[(x1, y1)] - cells[(x2, y2)] - 1;
                                return new List<Tuple<int, int>>();
                            }
                        }
                    }
                }

                int y3_i = cols[x1].BinarySearch(y1) + o1;
                if (y3_i >= 0 && y3_i < cols[x1].Count())
                {
                    int y3 = cols[x1][y3_i];
                    for (int o2 = -1; o2 <= 1; o2 += 2)
                    {
                        int x3_i = rows[y3].BinarySearch(x1) + o2;
                        if (x3_i >= 0 && x3_i < rows[y3].Count())
                        {
                            int x3 = rows[y3][x3_i];
                            if (cells[(x3, y3)] == 0)
                            {
                                cells[(x3, y3)] = cells[(x1, y1)] + 1;
                                new_starters.Add(new Tuple<int, int>(x3, y3));
                            }
                            else if (cells[(x3, y3)] < 0)
                            {
                                cells[(tx, ty)] = cells[(x1, y1)] - cells[(x3, y3)] - 1;
                                return new List<Tuple<int, int>>();
                            } 
                        }
                    }
                }
            }
        }
        else
        {
            for (int o1 = -1; o1 <= 1; o1 += 2)
            {
                int x2_i = rows[y1].BinarySearch(x1) + o1;
                if (x2_i >= 0 && x2_i < rows[y1].Count())
                {
                    int x2 = rows[y1][x2_i];
                    for (int o2 = -2; o2 <= 2; o2 += 4)
                    {
                        int y2_i = cols[x2].BinarySearch(y1) + o2;
                        if (y2_i >= 0 && y2_i  < cols[x2].Count())
                        {
                            int y2 = cols[x2][y2_i];
                            if (cells[(x2, y2)] == 0)
                            {
                                cells[(x2, y2)] = cells[(x1, y1)] - 1;
                                new_starters.Add(new Tuple<int, int>(x2, y2));
                            }
                            else if (cells[(x2, y2)] > 0)
                            {
                                cells[(tx, ty)] = cells[(x2, y2)] - cells[(x1, y1)] - 1;
                                return new List<Tuple<int, int>>();
                            }
                        }
                    }
                }

                int y3_i = cols[x1].BinarySearch(y1) + o1;
                if (y3_i >= 0 && y3_i < cols[x1].Count())
                {
                    int y3 = cols[x1][y3_i];
                    for (int o2 = -2; o2 <= 2; o2 += 4)
                    {
                        int x3_i = rows[y3].BinarySearch(x1) + o2;
                        if (x3_i >= 0 && x3_i < rows[y3].Count())
                        {
                            int x3 = rows[y3][x3_i];
                            if (cells[(x3, y3)] == 0)
                            {
                                cells[(x3, y3)] = cells[(x1, y1)] - 1;
                                new_starters.Add(new Tuple<int, int>(x3, y3));
                            }
                            else if (cells[(x3, y3)] > 0)
                            {
                                cells[(tx, ty)] = cells[(x3, y3)] - cells[(x1, y1)] - 1;
                                return new List<Tuple<int, int>>();
                            } 
                        }
                    }
                }
            }
        }

        return new_starters;
    }

    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        string[] targets = Console.ReadLine().Split(" ");
        int sx = Convert.ToInt32(targets[0]);
        int sy = Convert.ToInt32(targets[1]);
        tx = Convert.ToInt32(targets[2]);
        ty = Convert.ToInt32(targets[3]);

        if (sx == tx && sy == ty)
        {
            Console.WriteLine(0);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            string[] coords = Console.ReadLine().Split(" ");
            int x = Convert.ToInt32(coords[0]);
            int y = Convert.ToInt32(coords[1]);

            cells.Add((x, y), 0);

            if (!rows.ContainsKey(y))
                rows.Add(y, new List<int>());
            rows[y].Add(x);

            if (!cols.ContainsKey(x))
                cols.Add(x, new List<int>());
            cols[x].Add(y);
        }

        cells[(sx, sy)] = 1;
        cells[(tx, ty)] = -1;
        HashSet<Tuple<int, int>> starters = new HashSet<Tuple<int, int>>();
        starters.Add(new Tuple<int, int>(sx, sy));
        starters.Add(new Tuple<int, int>(tx, ty));
        
        while (starters.Count() > 0)
        {
            HashSet<Tuple<int, int>> new_starters = new HashSet<Tuple<int, int>>();
            foreach (Tuple<int, int> starter in starters)
            {
                new_starters.UnionWith(fly_from(starter.Item1, starter.Item2));
                if (cells[(tx, ty)] > 0)
                {
                    Console.WriteLine(cells[(tx, ty)]);
                    return;
                }
            }
            starters = new_starters;
        }

        Console.WriteLine(-1);
    }
}