use std::io;

fn is_unspooned(eqn: &Vec<String>, op: &str) -> bool {
    let eqn: Vec<i64> = eqn.iter()
        .map(|n| n.parse::<i64>().unwrap())
        .collect();
    let (x, y, z) = (eqn[0], eqn[1], eqn[2]);
    
    match op {
        "+" => x + y == z,
        "*" => x * y == z,
        _ => false
    }
}

fn main() {
    let stdin = io::stdin();
    let mut line = String::new();
    stdin.read_line(&mut line)
        .expect("invalid input");
    
    let eqn: Vec<&str> = line
        .trim()
        .split(" ")
        .collect();
         
    let v0: [&str; 3] = [eqn[0], eqn[2], eqn[4]];
    let op = eqn[1];

    for i in 0 .. 3 {
        // modify swap prefixes for x and y
        // while keeping z the same
        let x = i;
        let y = (i + 1) % 3;
        let z = (i + 2) % 3;

        for j in 1 .. v0[x].len() {
            for k in 1 .. v0[y].len() {
                let mut v: Vec<String> = Vec::new();
                v.resize(3, String::new());
                
                v[x] = format!("{}{}", &v0[y][..k], &v0[x][j..]);
                v[y] = format!("{}{}", &v0[x][..j], &v0[y][k..]);
                v[z] = String::from(v0[z]);

                if is_unspooned(&v, &op) {
                    println!("{} {} {} = {}", v[0], &eqn[1], v[1], v[2]);
                    return;
                }
            }
        }
    }
}