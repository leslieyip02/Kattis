use std::io;

fn read_i32s() -> Vec<i32> {
    let stdin = io::stdin();
    let mut line = String::new();
    stdin.read_line(&mut line)
        .expect("invalid input");

    line.trim()
        .split_whitespace()
        .map(|i| i.parse().unwrap())
        .collect()
}

fn ways_to_pair(n : i32) -> i32 {
    // ways to choose a pair from n different options
    // ⁿCᵣ = n! / (r! * (n - r)!)
    // ⁿC₂ = n! / (2 * (n - 2)!)
    //     = (1 * 2 * ... * n) / (2 * (1 * 2 * ... * (n - 2)))
    //     = (n * (n - 1)) / 2
    n * (n - 1) / 2
}

fn main() {
    let c = read_i32s()[0];
    for _ in 0 .. c {
        let line = read_i32s();
        let d = line[0];
        let n = line[1];

        let sequence = read_i32s();

        // store modulo of partial sums
        // if 2 partial sums have the same remainder,
        // that means their difference is divisble by 2
        // 
        // example:
        // { S₁ } = { 1, 2, 3 } 
        // { S₂ } = { 1, 2, 3, 4, 4}
        // ΣS₁ mod 4 = 2, ΣS₂ mod 4 = 2
        // ∴ (ΣS₂ - ΣS₁) mod 4 = 0
        // (14 - 6) mod 4 = 8 mod 4 = 0

        let mut remainders: Vec<i32> = Vec::new();
        remainders.resize(d as usize, 0);

        let mut r = 0;
        for i in 0 .. n as usize {
            r = (r + sequence[i]) % d;
            remainders[r as usize] += 1;
        }
        
        let mut divisible = remainders[0];
        for r in remainders {
            divisible += ways_to_pair(r);
        }

        println!("{}", divisible);
    }
}