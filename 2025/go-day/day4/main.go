package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

/*
--- Day 4: Ceres Search ---
"Looks like the Chief's not here. Next!" One of The Historians pulls out a device and pushes the only button on it. After a brief flash, you recognize the interior of the Ceres monitoring station!

As the search for the Chief continues, a small Elf who lives on the station tugs on your shirt; she'd like to know if you could help her with her word search (your puzzle input). She only has to find one word: XMAS.

This word search allows words to be horizontal, vertical, diagonal, written backwards, or even overlapping other words. It's a little unusual, though, as you don't merely need to find one instance of XMAS - you need to find all of them. Here are a few ways XMAS might appear, where irrelevant characters have been replaced with .:

..X...
.SAMX.
.A..A.
XMAS.S
.X....
The actual word search will be full of letters instead. For example:

MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX
In this word search, XMAS occurs a total of 18 times; here's the same word search again, but where letters not involved in any XMAS have been replaced with .:

....XXMAS.
.SAMXMS...
j...S..A...
..A.A.MS.X
XMASAMX.MM
X.....XA.A
S.S.S.S.SS
.A.A.A.A.A
..M.M.M.MM
.X.X.XMASX
Take a look at the little Elf's word search. How many times does XMAS appear?
*/

const (
	TARGET       = "XMAS"
	REVER_TARGET = "SAMX"
)

func main() {
	part1()
	part2()
}

func part2() {
	file, err := os.Open("input.txt")
	if err != nil {
		panic(err)
	}

	defer file.Close()

	scanner := bufio.NewScanner(file)

	var lines []string

	var total int

	for scanner.Scan() {
		txt := scanner.Text()
		lines = append(lines, txt)
	}

	matrix := make([][]rune, len(lines))
	for i, row := range lines {
		matrix[i] = []rune(row)
	}

	for x, row := range matrix {
		for y := range row {
			//  X
			x0 := matrix[x][y]
			if x+2 <= len(matrix)-1 && y+2 <= len(row)-1 {
				// 横向
				x1 := matrix[x][y+2]
				y0 := matrix[x+2][y]
				y1 := matrix[x+2][y+2]
				z0 := matrix[x+1][y+1]
				toRight := fmt.Sprintf("%s%s%s", string(x0), string(z0), string(y1))
				toLeft := fmt.Sprintf("%s%s%s", string(x1), string(z0), string(y0))
				if (toRight == "MAS" || toRight == "SAM") && (toLeft == "SAM" || toLeft == "MAS") {
					total++
				}
			}

		}
	}
	fmt.Printf("Part-2 Total is %d", total)
}

func part1() {
	file, err := os.Open("input.txt")
	if err != nil {
		panic(err)
	}

	defer file.Close()

	scanner := bufio.NewScanner(file)

	var lines []string

	var total int

	for scanner.Scan() {
		txt := scanner.Text()
		lines = append(lines, txt)
	}

	matrix := make([][]rune, len(lines))
	for i, row := range lines {
		matrix[i] = []rune(row)
	}
	for x, row := range matrix {
		for y := range row {
			// i, y
			// 横向
			x0 := matrix[x][y]

			// y + 3 (x, y) (x, y+1) (x, y+2) (x, y+3)

			// 横向
			if y+3 <= len(row)-1 {
				var buf bytes.Buffer
				buf.WriteRune(x0)
				for z := y + 1; z <= y+3; z++ {
					v := matrix[x][z]
					buf.WriteRune(v)
				}
				if buf.String() == TARGET || buf.String() == REVER_TARGET {
					total++
				}
			}
			// 竖直
			// (x, y) (x+1, y) (x + 2, y) (x + 3, y)
			if x+3 <= len(matrix)-1 {
				var buf bytes.Buffer
				buf.WriteRune(x0)

				for z := x + 1; z <= x+3; z++ {
					v := matrix[z][y]
					buf.WriteRune(v)
				}
				if buf.String() == TARGET || buf.String() == REVER_TARGET {
					total++
				}
			}
			// 对角 / \
			// (x, y)  |> (x +1, y+1) (x+2, y+2) (x+3, y+3)
			// 右边
			// x + 3
			// y + 3
			if x+3 <= len(matrix)-1 && y+3 <= len(row)-1 {
				var buf bytes.Buffer
				buf.WriteRune(x0)
				buf.WriteRune(matrix[x+1][y+1])
				buf.WriteRune(matrix[x+2][y+2])
				buf.WriteRune(matrix[x+3][y+3])

				if buf.String() == TARGET || buf.String() == REVER_TARGET {
					total++
				}
			}
			// 左边
			if x+3 <= len(matrix)-1 && y-3 >= 0 {
				var buf bytes.Buffer
				buf.WriteRune(x0)
				buf.WriteRune(matrix[x+1][y-1])
				buf.WriteRune(matrix[x+2][y-2])
				buf.WriteRune(matrix[x+3][y-3])

				if buf.String() == TARGET || buf.String() == REVER_TARGET {
					total++
				}

			}

		}
		// (I, y)
		// 横向三个
	}

	fmt.Printf("Part-1 Total is %d \n", total)

	// fmt.Println(matrix)
	// for _, item := range matrix {
	// 	fmt.Println(string(item))
	// }
}
