package main

import "fmt"

func main() {
	ret := uniquePaths2(3, 3)
	// 6 - 2
	//
	fmt.Println(ret)
}

func uniquePaths2(m int, n int) int {
	dp := make([][]int, m)

	for i := range dp {
		dp[i] = make([]int, n)
		dp[i][0] = 1
	}

	for i := range n {
		dp[0][i] = 1
	}
	dp[0][2] = 0

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if i == 0 && j == 2 {
				dp[i][j] = 0
			} else {
				dp[i][j] = dp[i-1][j] + dp[i][j-1]
			}
		}
	}
	fmt.Println(dp)

	return dp[m-1][n-1]
}

func uniquePaths(m int, n int) int {
	// 回溯
	// 如果往下走或者往右无法走就return
	// 动态规划

	// cell := make([][]int, m)

	// for i :=  range m {
	//     cell[i] = make([]int, n)
	// }
	// 只能向下 /  向右移动一步

	var backtrack func(pos []int)
	var find int
	backtrack = func(pos []int) {
		// 向下
		p1, p2 := pos[0], pos[1]

		if p1 == m {
			// fmt.Println(pos)
			find++
			return
		}

		if p2 == n {
			// fmt.Println(pos)
			find++
			return
		}

		// 最下面
		if p1 < m {
			pos = []int{p1 + 1, p2}
			backtrack(pos)
		}

		// 向右
		if p2 < n {
			pos = []int{p1, p2 + 1}
			backtrack(pos)
		}
	}

	backtrack([]int{1, 1})
	return find
}
