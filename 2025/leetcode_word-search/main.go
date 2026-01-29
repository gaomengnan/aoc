package main

import (
	"bytes"
	"fmt"
	"slices"
)

func main() {
	sample := [][]byte{
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'},
	}

	ret := exist(sample, "ABCCED")
	fmt.Println("hello", ret)
}

func exist(board [][]byte, word string) bool {
	m, n := len(board), len(board[0])

	var dfs func(w []byte, path [][]bool, x, y int)

	founded := false
	compW := []byte(word)

	dfs = func(w []byte, path [][]bool, x, y int) {
		fmt.Println("word", string(w))

		if bytes.Equal(w, compW) {
			founded = true
			return
		}

		if !bytes.HasPrefix(compW, w) {
			return
		}

		if len(w) >= len(compW) {
			return
		}

		if path == nil {
			path = make([][]bool, m)
			for i := 0; i < m; i++ {
				path[i] = make([]bool, n)
			}
		}

		// 上
		if x > 0 && !path[x-1][y] {
			newW := slices.Clone(w)
			newW = append(newW, board[x-1][y])

			path[x-1][y] = true

			dfs(newW, path, x-1, y)
			path[x-1][y] = false

		}

		// 下
		if x < m-1 && !path[x+1][y] {
			newW := slices.Clone(w)
			newW = append(newW, board[x+1][y])

			path[x+1][y] = true

			dfs(newW, path, x+1, y)
			path[x+1][y] = false

		}

		// 左边
		if y > 0 && !path[x][y-1] {
			newW := slices.Clone(w)
			newW = append(newW, board[x][y-1])

			path[x][y-1] = true

			dfs(newW, path, x, y-1)
			path[x][y-1] = false

		}
		// 右边
		if y < n-1 && !path[x][y+1] {
			newW := slices.Clone(w)
			newW = append(newW, board[x][y+1])

			path[x][y+1] = true

			dfs(newW, path, x, y+1)
			path[x][y+1] = false

		}
	}

	for i := range board {
		for j := range board[i] {
			path := make([][]bool, m)
			for i := 0; i < m; i++ {
				path[i] = make([]bool, n)
			}
			path[0][0] = true
			dfs([]byte{board[i][j]}, path, i, j)
		}
	}

	return founded
}
