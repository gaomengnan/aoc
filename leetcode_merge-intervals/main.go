package main

import "fmt"

func main() {
	fmt.Println("hello")

	inp := [][]int{
		{1, 3}, {2, 6}, {8, 10}, {15, 18},
	}
	// 1 2 3 6 8 10 15 18

	merge(inp)
}

func merge(intervals [][]int) [][]int {
	// 1 3  => 1 6   =>
	// 2 6     8 10
	c1 := 0
	for {
		c2 := c1 + 1
		_ = c2

		range1 := intervals[c1]
		range2 := intervals[c2]
		if len(range1) < 2 || len(range2) < 2 {
			// return false
		}

		start1, end1 := range1[0], range1[1]
		start2, end2 := range2[0], range2[1]
		hasOverlap := end1 >= start2 && end2 >= start1
		fmt.Println("res", hasOverlap)

		left := min(start1, start2)
		right := max(end1, end2)

		fmt.Println("left", left)
		fmt.Println("right", right)
		break
	}
	return nil
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func min(a, b int) int {
	if a > b {
		return b
	}

	return a
}
