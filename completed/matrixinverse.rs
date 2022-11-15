use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut c = 0;

    let mut m: Vec<Vec<i32>> = Vec::new();
    m.resize(2, Vec::new());

    for line in stdin.lock().lines().map(|l| l.unwrap()) {
        c += 1;

        if c % 3 == 0 {
            let a = m[0][0];
            m[0][0] = m[1][1];
            m[1][1] = a;

            m[0][1] *= -1;
            m[1][0] *= -1;

            let determinant = m[0][0] * m[1][1] - 
                m[0][1] * m[1][0];

            for i in 0 ..= 1 {
                for j in 0 ..= 1 {
                    m[i][j] *= determinant;
                }
            }

            println!("Case {}:", c / 3);
            println!("{} {}", m[0][0], m[0][1]);
            println!("{} {}", m[1][0], m[1][1]);
        } else {
            m[(c - 1) % 3] = line.split_whitespace()
                .map(|i| i.parse().unwrap())
                .collect();
        }
    }
}
