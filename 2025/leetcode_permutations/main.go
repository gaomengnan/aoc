package main

import "fmt"

func main() {
	fmt.Println("hello")
	a := []int{
		1, 2, 3,
	}
	permute(a)
}

func permute(nums []int) (out [][]int) {
	var recFunc func(path []int, used []bool)

	recFunc = func(path []int, used []bool) {
		// fmt.Println("path", path)

		if len(path) == len(nums) {
			pathCpy := make([]int, len(path))
			copy(pathCpy, path)
			out = append(out, pathCpy)
		}
		// [0]=true [1]=true [2]=true
		// [1 2 3] -> [1 2]
		// 1 2 3
		// 1 -> 1
		// 1-> 2 -> 3
		//

		for i := range nums {
			if used[i] {
				continue
			}

			used[i] = true
			path = append(path, nums[i])
			recFunc(path, used)
			path = path[:len(path)-1]
			used[i] = false
		}
	}

	// for i := range nums {
	//   var path []int
	//   path = append(path, i)
	//   used := make([]bool, 0)
	//   use[i] = true
	//   recFunc(path, used)

	// }

	// fmt.Println("out", out)
	used := make([]bool, len(nums))
	recFunc([]int{}, used)

	return out
}

func InArray[T comparable](arr []T, val T) bool {
	for _, item := range arr {
		if item == val {
			return true
		}
	}
	return false
}
