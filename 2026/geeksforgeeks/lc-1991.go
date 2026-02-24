package main

import "fmt"

func main() {
	fmt.Println(pivotIndex([]int{
		-1, -1, -1, -1, -1, -1,
	}))
}

func pivotIndex(nums []int) int {
	sumVal := 0
	for _, i := range nums {
		sumVal += i
	}
	current := 0
	for i, item := range nums {
		if (sumVal - item - current) == current {
			return i
		}
		current += item
	}

	return -1
}
