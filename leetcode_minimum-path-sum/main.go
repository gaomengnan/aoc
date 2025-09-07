package main

import "fmt"

func main() {
	fmt.Println("hello world")
}

// func minPathSum(grid [][]int) int {

// 	m, n := len(grid), len(grid[0])
// 	// m  *  n

// 	var backstrack func(x, y, sum int)

// 	minVal := 1 << 32

// 	backstrack = func(x, y, sum int) {
// 		if x >= m || y >= n {
// 			return
// 		}
// 		sum += grid[x][y]
// 		if x == m-1 && y == n-1 {
// 			// finish
// 			// fmt.Println("finish")
// 			// fmt.Println("sum", sum)
// 			minVal = min(sum, minVal)
// 			return
// 		}

// 		// 下
// 		backstrack(x+1, y, sum)
// 		// 右
// 		backstrack(x, y+1, sum)
// 	}

// 	backstrack(0, 0, 0)
// 	return minVal
// }

func minPathSum(grid [][]int) int {
	m, n := len(grid), len(grid[0])

	dp := make([][]int, m)

	for i := range m {
		dp[i] = make([]int, n)
	}

	dp[0][0] = grid[0][0]
	// fmt.Println("dp0", dp)

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i == 0 && j == 0 {
				continue
			}
			// cVal := grid[i][j]

			// 0 1
			minVal := 1 << 32
			if i >= 1 {
				minVal = min(minVal, dp[i-1][j])
			}

			if j >= 1 {
				minVal = min(minVal, dp[i][j-1])
			}

			dp[i][j] = minVal + grid[i][j]
		}
	}

	// fmt.Println("dp", dp)

	return dp[m-1][n-1]
}

func min[T Ordered](a, b T) T {
	if a > b {
		return b
	}

	return a
}

type Ordered interface {
	~int | ~float64 | ~int64 | ~string
}
