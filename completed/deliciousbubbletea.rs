use std::io;

fn read_int() -> i32 {
    let mut line = String::new();
    io::stdin().read_line(&mut line);

    line.trim()
        .parse::<i32>()
        .unwrap()
}
    
fn read_ints() -> Vec<i32> {
    let mut line = String::new();
    io::stdin().read_line(&mut line);

    line.split_whitespace()
        .map(|i| i.parse::<i32>().unwrap())
        .collect()
}

fn main() {
    let n = read_int() as usize;
    let teas = read_ints();

    let _m = read_int();
    let toppings = read_ints();

    let mut cheapest = i32::MAX;
    for i in 0 .. n {
        let pairings = read_ints();
        for j in pairings.iter().skip(1) {
            let combo = teas[i] + toppings[(j - 1) as usize];
            cheapest = cheapest.min(combo);
        }
    }

    let x = read_int();
    let y = (x / cheapest) - 1;
    println!("{}", y.max(0));
}
