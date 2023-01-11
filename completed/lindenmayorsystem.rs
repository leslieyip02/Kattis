use std::io;
use std::io::BufRead;
use std::error::Error;

fn main() -> Result<(), Box<dyn Error>> {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let mut line = lines.next().unwrap()?;
    let params = line.trim()
        .split(" ")
        .map(|i| i.parse::<u8>().unwrap())
        .collect::<Vec<u8>>();

    let n = params[0];
    let m = params[1];

    let mut rules = vec![String::new(); 26];
    
    for _ in 0 .. n {
        line = lines.next().unwrap()?;
        let params = line.trim()
            .split(" -> ")
            .collect::<Vec<&str>>();
            
        let x = params[0].chars()
            .next()
            .unwrap() as usize - 65;
        let y = String::from(params[1]);
        rules[x] = y;
    }

    line = lines.next().unwrap()?;
    let mut s0: String = String::from(line.trim());
    for _ in 0 .. m {
        let mut s1: Vec<String> = Vec::new();
        for c in s0.chars() {
            let i = c as usize - 65;
            if rules[i].is_empty() {
                s1.push(String::from(c));
            } else {
                s1.push(rules[i].clone());
            }
        }
        
        s0 = s1.concat();
    }

    println!("{}", s0);

    Ok(())
}