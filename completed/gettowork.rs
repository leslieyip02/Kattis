use std::io::{self};
use std::str::FromStr;

fn input<T: FromStr>() -> Result<T, T::Err> {
    let mut line = String::new();
    io::stdin().read_line(&mut line);

    line.trim()
        .parse::<T>()
}

fn split_input<T1: FromStr, T2: FromStr>(a: &mut T1, b: &mut T2) {
    let line = input::<String>()
        .unwrap();
    let mut line = line.split(" ");

    *a = line.next()
        .and_then(|i| i.parse::<T1>().ok())
        .unwrap();
    *b = line.next()
        .and_then(|i| i.parse::<T2>().ok())
        .unwrap();
}

fn possible(capacities: Vec<i32>) -> bool {
    capacities.iter()
        .all(|&car| car >= 0)
}

fn main() {
    let c = input::<u8>()
        .unwrap();

    for x in 1 ..= c {
        let mut n = 0;
        let mut t = 0;
        split_input::<usize, usize>(&mut n, &mut t);

        let mut cars: Vec<Vec<i32>> = Vec::new();
        cars.resize(n, Vec::new());

        let mut employees: Vec<i32> = Vec::new();
        employees.resize(n, 0);

        let mut capacities: Vec<i32> = Vec::new();
        capacities.resize(n, 0);

        let e = input::<i32>()
            .unwrap();
        for _i in 0 .. e {
            let mut h = 0;
            let mut p = 0;
            split_input::<usize, i32>(&mut h, &mut p);

            if h == t {
                continue;
            }

            if p > 0 {
                cars[h - 1].push(p);
            }
            employees[h - 1] += 1;
            capacities[h - 1] += p - 1;
        }

        print!("Case #{}: ", x);
        if !possible(capacities) {
            println!("IMPOSSIBLE");
        } else {
            for (i, j) in employees.iter().enumerate() {
                cars[i].sort_unstable();

                let mut v = 0;
                let mut unassigned = *j;
                while unassigned > 0 {
                    unassigned -= cars[i].pop()
                        .unwrap();
                    v += 1;
                }

                print!("{} ", v);
            }
            println!();
        }
    }
}