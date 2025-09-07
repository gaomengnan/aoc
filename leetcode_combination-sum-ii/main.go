package main

import (
	"fmt"
	"sort"
)

func main() {
	input := []int{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
	}
	ret := combinationSum2(input, 30)
	fmt.Println(ret)
}

func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	// fmt.Println(candidates)
	var result [][]int

	var recFun func(int, int, int, []int)
	// duplicates := make(map[string]struct{}, 0)

	recFun = func(index, t, sum int, path []int) {
		if t == sum {
			tmp := make([]int, len(path))
			copy(tmp, path)
			result = append(result, tmp)

			return
		}

		for i := index; i < len(candidates); i++ {

			if i > index && candidates[i] == candidates[i-1] {
				continue
			}

			rs := candidates[i] + sum
			if rs <= target {
				path = append(path, candidates[i])
				recFun(i+1, t, rs, path)
				path = path[:len(path)-1]
			} else {
				break
			}
		}
	}
	recFun(0, target, 0, []int{})
	return result
}
