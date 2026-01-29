package main

import (
	"fmt"
)

func grayCode(n int) []int {
	num := 1 << n // 节点总数
	used := make([]bool, num)
	path := make([]int, 0, num)
	path = append(path, 0)
	used[0] = true

	var res []int
	var found bool

	var dfs func(val int)
	dfs = func(val int) {
		if found {
			return
		}

		// 如果已经走完所有节点，并且最后一个和第一个只差一位
		if len(path) == num && isOneBitDifferent(path[0], path[len(path)-1]) {
			res = append([]int(nil), path...)
			found = true
			return
		}

		// 只翻转每一位，而不是遍历 0~num
		for bit := 0; bit < n; bit++ {
			next := val ^ (1 << bit)
			if used[next] {
				continue
			}
			used[next] = true
			path = append(path, next)

			dfs(next)

			// 回溯
			path = path[:len(path)-1]
			used[next] = false
		}
	}

	dfs(0)
	return res
}

func isOneBitDifferent(a, b int) bool {
	x := a ^ b
	return x != 0 && (x&(x-1)) == 0
}

func main() {
	out := grayCode(10)
	fmt.Println("长度:", len(out))
	fmt.Println("前20个:", out[:20])
}
