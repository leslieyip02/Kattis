use std::io;
use std::error::Error;

fn count(n: u64) -> u64 {
    if n <= 1 {
        return n;
    }

    // find leftmost set bit
    let mut x: u64 = n >> 1;
    let mut y: u32 = 0;
    while x > 0 {
        y += 1;
        x >>= 1;
    }

    // recursion using Sierpiński triangle
    let z = n - (1 << y);
    3u64.pow(y) + count(z) * 2
}

fn main() -> Result<(), Box<dyn Error>> {
    let mut line = String::new();
    io::stdin().read_line(&mut line)?;
    
    let n = line.trim()
        .parse::<u64>()?;

    println!("{}", count(n));
    Ok(())
}