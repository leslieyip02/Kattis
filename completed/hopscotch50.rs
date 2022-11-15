use std::io;

const INF: i32 = 1_000_000_000;

fn read_ints() -> Vec<i32> {
    let mut line = String::new();
    io::stdin().read_line(&mut line);

    line.split_whitespace()
        .map(|i| i.parse::<i32>().unwrap())
        .collect()
}

fn hop(x: usize, y: usize, k: i32,
    grid: &Vec<Vec<i32>>, mut memo: &mut Vec<Vec<i32>>) -> i32 {
    // revisiting a visited cell
    if memo[y][x] != -1 {
        return memo[y][x];
    }

    // end has been reached
    if grid[y][x] == k {
        return 0;
    }

    // dfs to find shortest path
    let mut shortest = INF;
    for j in 0 .. grid.len() {
        for i in 0 .. grid.len() {
            if grid[j][i] == grid[y][x] + 1 {
                let d = (x.abs_diff(i) + y.abs_diff(j)) as i32;
                shortest = shortest.min(d + 
                    hop(i, j, k, &grid, &mut memo));
            }
        }
    }

    // memoise
    memo[y][x] = shortest;
    shortest
}

fn main() {
    let line = read_ints();
    let n = line[0] as usize;
    let k = line[1];

    let mut grid: Vec<Vec<i32>> = Vec::new();
    let mut memo: Vec<Vec<i32>> = Vec::new();
    for _ in 0 .. n {
        grid.push(read_ints());
        memo.push(vec![-1; n]);
    }

    let mut shortest = INF;
    for y in 0 .. n {
        for x in 0 .. n {
            if grid[y][x] == 1 {
                shortest = shortest.min(hop(x, y, k, 
                    &grid, &mut memo));
            }
        }
    }

    if shortest == INF {
        println!("-1");
    } else { 
        println!("{}", shortest); 
    }
}
