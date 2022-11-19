use std::io::{self, BufRead};

fn convert_to_seconds(t: &str) -> i32 {
    let t: Vec<i32> = t
        .split(":")
        .map(|i| i.parse().unwrap())
        .collect();

    let h = t[0] * 60;
    let m = t[1];

    h + m
}

fn time_between(sunrise: &str, sunset: &str) -> i32 {
    convert_to_seconds(sunset) - convert_to_seconds(sunrise)
}

fn main() {
    let stdin = io::stdin();
    for line in stdin.lock().lines().map(|l| l.unwrap()) {
        let mut line: Vec<&str> = line
            .trim()
            .split_whitespace()
            .collect();

        let sunset = line.pop().unwrap();
        let sunrise = line.pop().unwrap();
        let t = time_between(sunrise, sunset);

        let h = t / 60;
        let m = t % 60;
        
        for i in line {
            print!("{} ", i);
        }

        println!("{} hours {} minutes", h, m);
    }
}