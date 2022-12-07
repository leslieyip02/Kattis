use std::io;
use std::error::Error;

fn main() -> Result<(), Box<dyn Error>> {
    let mut line = String::new();
    io::stdin().read_line(&mut line)?;
    let mut line = line.trim().split(" ");
    
    let h = line.next()
        .unwrap()
        .parse::<i32>()? as f64;
    let _r = line.next()
        .unwrap()
        .parse::<i32>()?;
    let da = line.next()
        .unwrap()
        .parse::<i32>()? as f64;
    let dw = line.next()
        .unwrap()
        .parse::<i32>()? as f64;
        
    // magic
    // ratio of weight is ratio of sqrt of densities
    let x = (h * da.sqrt()) / (da.sqrt() + dw.sqrt());
    println!("{}", x);

    Ok(())
}