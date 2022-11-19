use std::io;
use std::str::FromStr;

fn input<T: FromStr + Default>() -> T {
    let stdin = io::stdin();
    let mut line = String::new();
    stdin.read_line(&mut line)
        .expect("invalid input");
    line.trim()
        .parse::<T>()
        .unwrap_or_default()
}

fn main() {
    let line: Vec<i32> = input::<String>()
        .split(" ")
        .map(|i| i.parse().unwrap())
        .collect();
    let (n1, n2) = (line[0], line[1]);
    let n = (n1 + n2) as usize;
    
    let r1 = input::<String>();
    let r2 = input::<String>();
    
    let mut ants: Vec<char> = r1.chars()
        .rev()
        .collect();
    ants.extend(r2.chars());

    let t = input::<i32>();
    for _ in 0 .. t {
        let mut visited: Vec<bool> = Vec::new();
        visited.resize(n, false);
        
        for i in 0 .. n {
            if visited[i] {
                continue;
            }
        
            if i < (n - 1) &&
                r1.contains(ants[i]) &&
                !r1.contains(ants[i + 1]) {
                let tmp = ants[i];
                ants[i] = ants[i + 1];
                ants[i + 1] = tmp;
                
                visited[i] = true;
                visited[i + 1] = true;
            }
        }
    }
    
    for ant in ants {
        print!("{}", ant);
    }
}