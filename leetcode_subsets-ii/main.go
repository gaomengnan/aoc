package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	sample := []int{
		5, 5, 5, 5, 5,
		// 1, 2, 2,
	}
	subsetsWithDup(sample)
}

func subsetsWithDup(nums []int) (out [][]int) {
	sort.Ints(nums)
	var dfs func(path []int, startIdx int)

	// duplicates := make(map[string]struct{}, 0)

	used := make([]bool, len(nums))

	dfs = func(path []int, startIdx int) {
		tmp := make([]int, len(path))
		copy(tmp, path)
		// _, ok := duplicates[JoinInts(tmp, ",")]
		// if !ok {
		// 	duplicates[JoinInts(tmp, ",")] = struct{}{}
		// }
		out = append(out, tmp)

		for idx := startIdx; idx < len(nums); idx++ {
			if idx > 0 && nums[idx] == nums[idx-1] && !used[idx-1] {
				continue
			}
			used[idx] = true
			path = append(path, nums[idx])
			dfs(path, idx+1)
			// used[idx] = true
			used[idx] = false

			path = path[:len(path)-1]
		}
	}

	dfs([]int{}, 0)
	fmt.Println("return", out)
	return
}

func JoinInts(nums []int, sep string) string {
	strArr := make([]string, len(nums))
	for i, n := range nums {
		strArr[i] = strconv.Itoa(n)
	}
	return strings.Join(strArr, sep)
}
