using System;
using System.Collections.Generic;

class Program
{
    public static int[][] offset = new int[][] {
        new int[] { 0, -1 },
        new int[] { 1, 0 },
        new int[] { 0, 1 }, 
        new int[] { -1, 0 }
    };

    class Maze
    {
        private int h;
        private int w;
        public bool multiplePaths = false;
        public int [,] grid;
        public string[] walls;
        public List<Tuple<int, int>> openings = new List<Tuple<int, int>>();
        
        public Maze(int h, int w, string[] walls)
        {
            this.h = h;
            this.w = w;

            grid = new int[h, w];
            this.walls = walls;

            this.FindOpenings();
        }

        private string CanGoTo(int x, int y)
        {
            return Convert.ToString(Convert.ToInt32(this.walls[y][x].ToString(), 16), 2)
                                    .PadLeft(4, '0');
        }

        private void FindOpenings()
        {
            for (int y = 0; y < h; y++)
            {
                if (this.CanGoTo(0, y)[3] == '0')
                    this.openings.Add(new Tuple<int, int>(0, y));

                if (this.CanGoTo(this.w - 1, y)[1] == '0')
                    this.openings.Add(new Tuple<int, int>(this.w - 1, y));

                if (this.openings.Count == 2)
                    return;
            }

            for (int x = 0; x < w; x++)
            {
                if (this.CanGoTo(x, 0)[0] == '0')
                    this.openings.Add(new Tuple<int, int>(x, 0));

                if (this.CanGoTo(x, this.h - 1)[2] == '0')
                    this.openings.Add(new Tuple<int, int>(x, this.h - 1));

                if (this.openings.Count == 2)
                    return;
            }
        }

        public void Flood(int x, int y, int z)
        {
            if (this.grid[y, x] != 0)
                return;

            this.grid[y, x] = z;
            string dirs = this.CanGoTo(x, y);
            for (int i = 0; i < 4; i++)
            {
                int nx = x + offset[i][0];
                int ny = y + offset[i][1];
                if (nx < 0 || nx >= this.w || ny < 0 || ny >= this.h)
                    continue;

                if (dirs[i] == '0')
                    if (this.grid[ny, nx] >= z)
                        this.multiplePaths = true;
                    else
                        this.Flood(nx, ny, z + 1);
            }
        }
    }
    
    static void Main(string[] args)
    {
        int h, w;
        string[] line = Console.ReadLine().Split(" ");
        h = Convert.ToInt32(line[0]);
        w = Convert.ToInt32(line[1]);

        while (h != 0 && w != 0)
        {
            string[] walls = new string[h];
            for (int i = 0; i < h; i++)
                walls[i] = Console.ReadLine();

            Maze maze = new Maze(h, w, walls);
            maze.Flood(maze.openings[0].Item1, maze.openings[0].Item2, 1);
            
            if (maze.grid[maze.openings[0].Item2, maze.openings[0].Item1] == 0 ||
                maze.grid[maze.openings[1].Item2, maze.openings[1].Item1] == 0)
            {
                Console.WriteLine("NO SOLUTION");
            }
            else
            {
                bool allReachable = true;
                for (int y = 0; y < h; y++)
                {
                    for (int x = 0; x < w; x++)
                    {
                        if (maze.grid[y, x] == 0)
                        {
                            allReachable = false;
                            goto searched;
                        }
                    }
                }
                
                searched:
                    Console.WriteLine(!allReachable ? "UNREACHABLE CELL" :
                        maze.multiplePaths ? "MULTIPLE PATHS" : "MAZE OK");
            }

            line = Console.ReadLine().Split(" ");
            h = Convert.ToInt32(line[0]);
            w = Convert.ToInt32(line[1]);
        }
    }
}