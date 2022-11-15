use std::io::{self};
use std::str::FromStr;
use std::f64::consts::PI;

fn input<T: FromStr>() -> Result<T, T::Err> {
    let mut line = String::new();
    io::stdin().read_line(&mut line);

    line.trim()
        .parse::<T>()
}

fn draw(x: &mut f64, y: &mut f64, d: i32, a: i32) {
    let d = d as f64;
    let a_rad = PI * (a as f64) / 180.0;

    *x += a_rad.sin() * d;
    *y += a_rad.cos() * d;
}

fn distance(x: f64, y: f64) -> i32 {
    (x.powf(2.0) + y.powf(2.0)).sqrt()
        .round() as i32
}

fn main() {
    let t = input::<i32>()
        .unwrap();

    for _i in 0 .. t {
        let n = input::<i32>()
            .unwrap();

        let mut x: f64 = 0.0;
        let mut y: f64 = 0.0;
        let mut a: i32 = 0;

        for _j in 0 .. n {
            let p = input::<String>()
                .unwrap();
            let mut p = p.split(" ");

            let c: &str = p.next()
                .unwrap();

            let d: i32 = p.next()
                .and_then(|i| i.parse().ok())
                .unwrap();

            match c {
                "fd" => draw(&mut x, &mut y, d, a),
                "bk" => draw(&mut x, &mut y, -d, a),
                "lt" => a = (a + d) % 360,
                "rt" => a = (a - d % 360 + 360) % 360,
                _    => ()
            }
        }

        println!("{}", distance(x, y));
    }
}