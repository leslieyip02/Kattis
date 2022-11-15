use std::io::{self, BufRead};
use std::cmp::Ordering;

fn all_zero(t: &Vec<i32>) -> bool {
    t.iter().all(|&roll| roll == 0)
}

// get all possible combinations of die
fn possbilities(d0: i32, d1: i32) -> Vec<(i32, i32)> {
    let mut p: Vec<(i32, i32)> = Vec::new();
    
    if d0 != -1 && d1 != -1 {
        p.push((d0, d1));
    } else {
        for i in 1 ..= 6 {
            for j in 1 ..= 6 {
                p.push((
                    if d0 == -1 { i } else { d0 },
                    if d1 == -1 { j } else { d1 }
                ));
            }
        }
    }

    p
}

fn score(r: (i32, i32)) -> i32 {
    let x = r.0;
    let y = r.1;
    
    // mia (1 2 or 2 1)
    if x + y == 3 {
        10000
    } else {
        match x.cmp(&y) {
            Ordering::Greater => x * 10 + y,
            Ordering::Equal   => x * 100,
            Ordering::Less    => y * 10 + x
        }
    }
}

fn main() {
    let stdin = io::stdin();
    for line in stdin.lock().lines().map(|l| l.unwrap()) {
        let t: Vec<i32> = line.split_whitespace()
            .map(|roll| roll.parse().unwrap_or(-1))
            .collect();

        if all_zero(&t) {
            break;
        }

        let p1_rolls = possbilities(t[0], t[1]);
        let p2_rolls = possbilities(t[2], t[3]);

        let mut p1_wins = 0;
        let mut rounds = 0;
        for p1 in p1_rolls {
            let p1_score = score(p1);
            for p2 in &p2_rolls {
                let p2_score = score(*p2);

                if p1_score > p2_score {
                    p1_wins += 1;
                }
                rounds += 1;
            }
        }

        if p1_wins == 0 {
            println!("0");
        } else if p1_wins == rounds {
            println!("1");
        } else {
            for i in (2 ..= p1_wins).rev() {
                if p1_wins % i == 0 && rounds % i == 0 {
                    p1_wins /= i;
                    rounds /= i;
                    break;
                }
            }
    
            println!("{}/{}", p1_wins, rounds);
        }
    }
}