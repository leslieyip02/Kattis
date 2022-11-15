use std::io::{self, BufRead};

// 1 if O wins, -1 if X wins, 0 if no winner
fn winner(game: [[i32; 3]; 3]) -> i32 {
    // straight horizontal / vertical
    for i in 0 .. 3 {
        if game[i][0] == game[i][1] && 
            game[i][1] == game[i][2] &&
            game[i][0] != 0 {
           return game[i][0];
        }

        if game[0][i] == game[1][i] && 
            game[1][i] == game[2][i] &&
            game[0][i] != 0 {
            return game[0][i];
        }
    }

    // diagonals
    if (game[0][0] == game[1][1] &&
        game[1][1] == game[2][2] ||
        game[2][0] == game[1][1] &&
        game[1][1] == game[0][2]) &&
        game[1][1] != 0 {
        return game[1][1];
    }

    return 0;
}

fn main() {
    let stdin = io::stdin();
    let mut line = String::new();
    stdin.read_line(&mut line);
    let _c = line.trim()
        .parse::<i32>()
        .unwrap();

    for line in stdin.lock().lines().map(|l| l.unwrap()) {
        let line = format!("{:0>8}", line);
        let mut bits: Vec<u32> = line.chars()
            .map(|i| i.to_digit(10).unwrap())
            .collect();
        
        let mut game: [[i32; 3]; 3] = [[0; 3]; 3];

        // set all played bits to 1 (i.e. played by O)
        for i in 0 .. 3 {
            let mut bit = bits.pop()
                .unwrap();
            for j in 0 .. 3 {
                if bit & 1 == 1 {
                    game[i][j] = 1;
                }
                bit >>= 1;
            }
        }

        // set bits played by X to -1
        for i in 0 .. 3 {
            let mut bit = bits.pop()
                .unwrap();
            for j in 0 .. 3 {
                if bit & 1 == 1 {
                    game[i][j] *= -1;
                }
                bit >>= 1;
            }
        }

        let result = winner(game);
        match result {
            1 => println!("O wins"),
            -1 => println!("X wins"),
            _ => {
                let cat = &line[5..8];
                // if all bits are set,
                if cat == "777" {
                    println!("Cat's");
                } else {
                    println!("In progress");
                }
            }
        }
    }
}