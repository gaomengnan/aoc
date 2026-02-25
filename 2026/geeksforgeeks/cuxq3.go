package main

import "fmt"

func findDiagonalOrder(mat [][]int) []int {
	m := len(mat)
	n := len(mat[0])
	x := 0
	y := 0

	directions := [][]int{
		{-1, 1},
		{1, -1},
	}
	ans := make([]int, 0, m*n)

	direction := 0

	for {
		// fmt.Printf("x = %d, y =%d, direc = %d \r\n", x, y, direction)
		ans = append(ans, mat[x][y])

		if x == m-1 && y == n-1 {
			break
		}

		// next step
		_x := x + directions[direction][0]
		_y := y + directions[direction][1]

		switch direction {
		case 0:
			if _x < 0 || _y > n-1 {
				// 右边还有空间
				if _y <= n-1 {
					y = y + 1
				} else {
					x = x + 1
				}
				direction = 1
			} else {
				x = _x
				y = _y
			}
		case 1:
			if _y < 0 || _x > m-1 {
				// 右边还有空间
				if _x <= m-1 {
					x += 1
				} else {
					y += 1
				}
				direction = 0
			} else {
				x = _x
				y = _y
			}
		}
	}
	// fmt.Printf("%#v \r\n", ans)
	return ans
}

// 0,0 0,1 1,0

func main() {
	// Example 1
	mat1 := [][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}
	result1 := findDiagonalOrder(mat1)
	fmt.Printf("Example 1: %#v \r\n", result1)
	// Expected: [1,2,4,7,5,3,6,8,9]

	// Example 2
	mat2 := [][]int{
		{1, 2},
		{3, 4},
	}
	result2 := findDiagonalOrder(mat2)
	fmt.Printf("Example 2: %#v", result2)
	// Expected: [1,2,3,4]
}
