use std::io;

fn next_fib(n: i32) -> i32 {
    let mut x = 1;
    let mut y = 1;
    while x + y <= n {
        let z = x;
        x += y;
        y = z;
    }

    return x;
}

fn main() {
    let stdin = io::stdin();
    let mut n = String::new();
    stdin.read_line(&mut n);
    let mut n = n.trim()
        .parse::<i32>()
        .unwrap();

    let mut seq: Vec<i32> = Vec::new();
    while n > 0 {
        let k = next_fib(n);
        seq.push(k);
        n -= k;
    }

    for i in seq.iter().rev() {
        print!("{} ", i);
    }
}