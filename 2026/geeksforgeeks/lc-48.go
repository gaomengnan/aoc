// LeetCode 48 - Rotate Image
// 旋转矩阵 90 度顺时针（原地）
//
// 思路：
// 1. 顺时针旋转 90 度相当于 (i,j) -> (j, n-i)
// 2. 每个位置的旋转涉及 4 个位置的循环替换
// 3. 分层处理：从外层向内层，每层做 4 点轮换
// 4. 递归实现 4 点轮换：保存起点值，不断将下一个位置的值移到当前位置
//
// 解法：
// - 外层循环按层遍历 (layer)
// - 内层循环遍历每层的边（除了最后一个点，避免重复）
// - 递归函数 R 处理 4 点轮换
package main

import "slices"

func rotate(matrix [][]int) {
	n := len(matrix) - 1
	// for i, pos := range matrix {
	//     for j :=  range pos {
	//         // pos(i, j)
	//         // target(j, n-i)
	//         fmt.Printf("(%d,%d) => (%d,%d)\r\n", i, j, j, n-i)

	//     }
	// }

	var R func(spos, npos []int, prePosVal int)
	R = func(spos, npos []int, prePosVal int) {
		nPosVal := matrix[npos[0]][npos[1]]
		matrix[npos[0]][npos[1]] = prePosVal
		if slices.Equal(spos, npos) {
			return
		}
		R(spos, []int{npos[1], n - npos[0]}, nPosVal)
	}
	size := n + 1
	// 一层一层转
	for layer := 0; layer < size/2; layer++ {
		first := layer
		last := n - layer
		// 这一层上边这一条边上的每个点，都作为一个 4 点轮换的起点
		for j := first; j < last; j++ {
			start := []int{first, j}
			next := []int{j, n - first} // (i,j) -> (j, n-i) 里的下一站
			R(start, next, matrix[first][j])
		}
	}

	// for _, row := range matrix {
	//     fmt.Printf("%v\r\n", row)
	// }
}

// n = n-1

// 0,0 => 0, n
// 0,1 => 1,n

func main() {
	testCases := []struct {
		input    [][]int
		expected [][]int
	}{
		{
			input:    [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
			expected: [][]int{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}},
		},
		{
			input:    [][]int{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
			expected: [][]int{{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}},
		},
		{
			input:    [][]int{{1}},
			expected: [][]int{{1}},
		},
		{
			input:    [][]int{{1, 2}, {3, 4}},
			expected: [][]int{{3, 1}, {4, 2}},
		},
	}

	for i, tc := range testCases {
		inputCopy := make([][]int, len(tc.input))
		for j := range tc.input {
			inputCopy[j] = make([]int, len(tc.input[j]))
			copy(inputCopy[j], tc.input[j])
		}

		rotate(inputCopy)

		pass := true
		if len(inputCopy) != len(tc.expected) {
			pass = false
		} else {
			for j := range inputCopy {
				if !slices.Equal(inputCopy[j], tc.expected[j]) {
					pass = false
					break
				}
			}
		}

		if pass {
			println("Test", i+1, "PASSED")
		} else {
			println("Test", i+1, "FAILED")
			println("  Input:", tc.input)
			println("  Expected:", tc.expected)
			println("  Got:", inputCopy)
		}
	}
}
