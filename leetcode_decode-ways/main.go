package main

import (
	"fmt"
	"strconv"
)

func main() {
	sample := "111111111111111111111111111111111111111111111"

	res := numDecodings(sample)
	fmt.Println(res)
}

func numDecodings(s string) int {
	dicts := make(map[string]string)
	index := 1
	for ch := 'A'; ch <= 'Z'; ch++ {
		// fmt.Printf("%c ", ch)
		// strconv.Itoa(index)
		dicts[strconv.Itoa(index)] = string(ch)
		index++
	}
	// fmt.Println(dicts)

	// iters := []rune(s)

	// for _, ch := range iters {
	// 	fmt.Println(string(ch))
	// }

	var counter int
	res := make([][]string, 0)

	var dfs func(startIdx int)

	dfs = func(startIdx int) {
		if startIdx >= len(s) {
			// var tmp = make([]string, len(path))
			// copy(tmp, path)
			// res = append(res, tmp)

			counter++
			return
		}

		// 一位
		val := s[startIdx]
		if _, ok := dicts[string(val)]; ok {
			// path = append(path, v)

			dfs(startIdx + 1)
			// path = path[:len(path)-1]
		}

		if startIdx < len(s)-1 {
			// 二位
			val2 := s[startIdx : startIdx+2]

			if _, ok := dicts[string(val2)]; ok {
				// path = append(path, v)
				dfs(startIdx + 2)
				// path = path[:len(path)-1]
			}
		}
	}

	dfs(0)

	// fmt.Println(res)

	// 转换为 []string
	// strs := make([]string, len(res))
	// for i, row := range res {
	// 	strs[i] = string(row)
	// }
	// fmt.Println(strs) // [你好 世界]

	return len(res)
}

// 2 2 6
// 2 26
// 22 6

// 3456
