/*
--- Day 6: Guard Gallivant ---
The Historians use their fancy device again, this time to whisk you all away to the North Pole prototype suit manufacturing lab... in the year 1518! It turns out that having direct access to history is very convenient for a group of historians.

You still have to be careful of time paradoxes, and so it will be important to avoid anyone from 1518 while The Historians search for the Chief. Unfortunately, a single guard is patrolling this part of the lab.

Maybe you can work out where the guard will go ahead of time so that The Historians can search safely?

You start by making a map (your puzzle input) of the situation. For example:

....#.....
.........#
..........
..#.......
.......#..
..........
.#..^.....
........#.
#.........
......#...
The map shows the current position of the guard with ^ (to indicate the guard is currently facing up from the perspective of the map). Any obstructions - crates, desks, alchemical reactors, etc. - are shown as #.

Lab guards in 1518 follow a very strict patrol protocol which involves repeatedly following these steps:

If there is something directly in front of you, turn right 90 degrees.
Otherwise, take a step forward.
Following the above protocol, the guard moves up several times until she reaches an obstacle (in this case, a pile of failed suit prototypes):

....#.....
....^....#
..........
..#.......
.......#..
..........
.#........
........#.
#.........
......#...
Because there is now an obstacle in front of the guard, she turns right before continuing straight in her new facing direction:

....#.....
........>#
..........
..#.......
.......#..
..........
.#........
........#.
#.........
......#...
Reaching another obstacle (a spool of several very long polymers), she turns right again and continues downward:

....#.....
.........#
..........
..#.......
.......#..
..........
.#......v.
........#.
#.........
......#...
This process continues for a while, but the guard eventually leaves the mapped area (after walking past a tank of universal solvent):

....#.....
.........#
..........
..#.......
.......#..
..........
.#........
........#.
#.........
......#v..
By predicting the guard's route, you can determine which specific positions in the lab will be in the patrol path. Including the guard's starting position, the positions visited by the guard before leaving the area are marked with an X:

....#.....
....XXXXX#
....X...X.
..#.X...X.
..XXXXX#X.
..X.X.X.X.
.#XXXXXXX.
.XXXXXXX#.
#XXXXXXX..
......#X..
In this example, the guard will visit 41 distinct positions on your map.

Predict the path of the guard. How many distinct positions will the guard visit before leaving the mapped area?
 *  */
use std::fs::File;
use std::io::{self, BufRead, BufReader};
// use std::thread::sleep;
// use std::time::Duration;

fn main() {
    let _ = solve1();
    let _ = solve2();
}
#[derive(Debug)]
enum Direction {
    Up,
    Down,
    Left,
    Right,
}

fn solve1() -> io::Result<()> {
    let f = File::open("input.txt")?;
    let r = BufReader::new(f);

    let mut matrix: Vec<Vec<u8>> = Vec::new();

    for line in r.lines() {
        match line {
            Ok(line_content) => {
                matrix.push(line_content.as_bytes().to_vec());
                // println!("{:?}", line_content);
            }

            Err(e) => {
                eprintln!("Error reading line: {}", e); // 错误处理
            }
        }
    }

    // for row in &matrix {
    //     println!("{:?}", row);
    // }
    //  首先找到 ^ 的位置
    //  ^ ascii 为 94
    let mut c_pos = Vec::new();

    'outer: for (i, row) in matrix.iter().enumerate() {
        for (j, &byte) in row.iter().enumerate() {
            if byte == 94 {
                c_pos.push(i);
                c_pos.push(j);
                break 'outer;
            }
        }
    }

    // let mut x = c_pos[0];
    // let mut y = c_pos[1];
    let mut direct = Direction::Up;

    // println!("{:?}", c_pos);
    // matrix[c_pos[0]][c_pos[1]] = 'X' as u8;

    'lp: while c_pos[0] < matrix.len() {
        // println!("+++++++++++++++++++++++++++++++++++++++++");
        // println!("current pos is {:?}", c_pos);
        // println!("current direct is {:?}", direct);
        matrix[c_pos[0]][c_pos[1]] = b'X';
        // current = {x, y}

        let next_b: u8;

        match direct {
            // 向上 向右
            //  x -1
            Direction::Up => {
                // println!("Moving Up");
                // if c_pos[0] - 1 < 0 {
                //     break 'lp;
                // }

                if c_pos[0] == 0 {
                    // println!("Out Scope");
                    break 'lp;
                }
                if let Some(x0) = matrix.get(c_pos[0] - 1) {
                    next_b = x0[c_pos[1]];
                } else {
                    break 'lp;
                }

                if next_b != 35 {
                    c_pos[0] -= 1;
                }
            }
            // x + 1
            Direction::Down => {
                // println!("Moving Down");
                if let Some(x0) = matrix.get(c_pos[0] + 1) {
                    next_b = x0[c_pos[1]];
                } else {
                    break 'lp;
                }

                if next_b != 35 {
                    c_pos[0] += 1;
                }
            }
            // y -1
            Direction::Left => {
                // println!("Moving Left");
                if let Some(x0) = matrix[c_pos[0]].get(c_pos[1] - 1) {
                    next_b = *x0;
                } else {
                    break 'lp;
                }

                if next_b != 35 {
                    c_pos[1] -= 1;
                }
            }

            // y + 1
            Direction::Right => {
                // println!("Moving Right");
                if let Some(x0) = matrix[c_pos[0]].get(c_pos[1] + 1) {
                    next_b = *x0;
                } else {
                    break 'lp;
                }

                if next_b != 35 {
                    c_pos[1] += 1;
                }
            }
        }

        // println!("next val is {}", (next_b as char));
        // println!("next val is {}", next_b);
        // 如果下一个是# 那么需要掉头

        if next_b == 35 {
            // 向右边转
            direct = match direct {
                Direction::Up => Direction::Right,
                Direction::Down => Direction::Left,
                Direction::Left => Direction::Up,
                Direction::Right => Direction::Down,
            }
        }
        // println!("+++++++++++++++++++++++++++++++++++++++++");
        // sleep(Duration::from_secs(2));
        // println!("next val is {}", next_b);
        // c_pos[0] = c_pos[0] + 1;
    }
    let mut ans = 0;
    for row in &matrix {
        for i in row {
            // print!("{}", (*i as char).to_string());
            if (*i as char).to_string() == "X" {
                ans += 1;
            }
        }
        // println!("===");
    }

    println!("Ans is {}", ans);

    Ok(())
}

fn solve2() -> io::Result<()> {
    Ok(())
}
