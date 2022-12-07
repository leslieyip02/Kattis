use std::io;
use std::error::Error;
use std::f64::consts::E;

fn main() -> Result<(), Box<dyn Error>> {
    let mut line = String::new();
    io::stdin().read_line(&mut line)?;
    
    let n = line.trim()
        .parse::<usize>()?;

    if n == 1 {
        println!("{}", 1.0);
    } else if n > 20 {
        // convergence
        let p = 1.0 - 1.0 / E;
        println!("{}", p);
    } else {
        let mut dp: Vec<f64> = Vec::new();
        dp.resize(n, 0.0);

        dp[0] = 0.0;
        dp[1] = 1.0;

        // count derangements
        // https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/
        for i in 2 .. n {
            dp[i] = (i as f64) * (dp[i - 1] + dp[i - 2]);
        }

        // find probability that no one gifts themselves 
        for i in 2 ..= n {
            dp[n - 1] /= i as f64;
        }

        let p = 1.0 - dp[n - 1];
        println!("{}", p);
    }

    Ok(())
}