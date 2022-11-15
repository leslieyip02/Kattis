use std::io;

fn main() {
    let stdin = io::stdin();
    let mut p = String::new();
    stdin.read_line(&mut p);
    let mut p = p.trim().split(" ");

    let n: i32 = p.next()
        .and_then(|i| i.parse().ok())
        .unwrap();
    let m: i32 = p.next()
        .and_then(|i| i.parse().ok())
        .unwrap();
    
    let max_lines = n * 2 - 3;
    let min_lines = n - 1;
    if m < min_lines || m > max_lines {
        println!("-1");
        return;
    }
    
    let mut buses: Vec<(i32, i32)> = Vec::new();
    
    for i in 2 ..= n {
        buses.push((1, i));
    }

    for i in 2 .. n {
        buses.push((i, n));
    }
    
    if buses.len() < m as usize {
        println!("-1");
    } else {
        for i in 0 .. m as usize {
            println!("{} {}", buses[i].0, buses[i].1);
        }
    }
}
