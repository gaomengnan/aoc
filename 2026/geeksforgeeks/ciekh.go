package main

import (
	"fmt"
	"math"
)

func setZeroes(matrix [][]int) {
	m := len(matrix)
	n := len(matrix[0])
	signal := math.MaxInt
	for i := range matrix {
		// fmt.Printf("%#v\r\n", item)
		for j := range matrix[i] {
			if matrix[i][j] == signal {
				continue
			}

			if matrix[i][j] == 0 {
				for x := 0; x < m; x++ {
					if matrix[x][j] != 0 {
						matrix[x][j] = signal
					}
				}

				for x := 0; x < n; x++ {
					if matrix[i][x] != 0 {
						matrix[i][x] = signal
					}
				}
			}
		}
	}

	for i := range matrix {
		// fmt.Printf("%#v\r\n", item)
		for j := range matrix[i] {
			if matrix[i][j] == signal {
				matrix[i][j] = 0
			}
		}
	}

	// for _, row :=  range matrix {
	//     fmt.Printf("%#v\r\n", row)
	// }
}

func run() string {
	matrix := [][]int{
		{1, 1, 1},
		{1, 0, 1},
		{1, 1, 1},
	}
	setZeroes(matrix)
	return fmt.Sprint(matrix)
}

func main() {
	fmt.Println(run())
}
