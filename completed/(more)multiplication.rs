use std::io::{self, BufRead};

fn to_digits(mut n: i32, len: Option<i32>) -> Vec<i32> {
    let mut digits: Vec<i32> = Vec::new();
    
    while n > 0 {
        digits.push(n % 10);
        n /= 10;
    }

    match len {
        Some(len) => {
            while digits.len() < len as usize {
                digits.push(0);
            }
        },
        None => ()
    }
    
    digits.reverse();
    return digits;
}

fn main() {
    let stdin = io::stdin();
    for line in stdin.lock().lines().map(|l| l.unwrap()) {
        let nums = line.split_whitespace()
            .map(|i| i.parse().unwrap())
            .collect::<Vec<i32>>();

        let a = nums[0];
        let b = nums[1];
        
        if a == 0 && b == 0 {
            return;
        }
            
        let result = to_digits(a * b, None);
        let a = to_digits(a, None);
        let b = to_digits(b, None);
        
        let mut grid = vec![vec![0; a.len()]; b.len()];
        for (i, y) in b.iter().enumerate() {
            for (j, x) in a.iter().enumerate() {
                grid[i][j] = x * y;
            }
        }

        let divider = format!("| +{} |", a.iter()
            .map(|_| "---+")
            .collect::<Vec<&str>>()
            .join(""));
        
        let frame = format!("+{}+", "-".repeat(divider.len() - 2));
        
        println!("{}", frame);
        println!("|   {}   |", a.iter()
            .map(|i| i.to_string())
            .collect::<Vec<String>>()
            .join("   "));
        println!("{}", divider);

        let vertical_digits = &result[0 .. result.len() - a.len()];
        let mut verticals: Vec<Vec<String>> = Vec::new();
        for digit in vertical_digits {
            verticals.push(vec![digit.to_string(), String::from(" ")]);
        } 
        
        for i in 0 .. verticals.len() {
            let c = if i == 0 { " " } else { "/" };
            verticals[i].push(String::from(c));
            verticals[i].reverse();
        }

        verticals.reverse();
        while verticals.len() < grid.len() {
            verticals.push(vec![String::from(" "); 3]);
        }
        
        for (i, row) in grid.iter().enumerate() {
            let digits = row.iter()
                .map(|j| to_digits(*j, Some(2)))
                .collect::<Vec<Vec<i32>>>();
            let vertical = verticals.pop()
                .unwrap();

            println!("|{}|{}| |", vertical[0],
                digits.iter()
                    .map(|i| format!("{} /", i[0]))
                    .collect::<Vec<String>>()
                    .join("|"));
            println!("|{}|{}|{}|", vertical[1],
                digits.iter()
                    .map(|_| " / ")
                    .collect::<Vec<&str>>()
                    .join("|"), b[i]);
            println!("|{}|{}| |", vertical[2],
                digits.iter()
                    .map(|i| format!("/ {}", i[1]))
                    .collect::<Vec<String>>()
                    .join("|"));
            println!("{}", divider);
        }
        
        let horizontal_digits = &result[result.len() - a.len() ..];
        let horizontal = format!("|{} {}    |",
            if horizontal_digits.len() == result.len() { " " } else { "/" },
            horizontal_digits.iter()
                .map(|i| i.to_string())
                .collect::<Vec<String>>()
                .join(" / "));
        println!("{}", horizontal);

        println!("{}", frame);
    }
}