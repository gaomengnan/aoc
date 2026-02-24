package main

import "sort"

func merge(intervals [][]int) [][]int {
	ans := make([][]int, 0, len(intervals))
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	ans = append(ans, intervals[0])

	for _, item := range intervals[1:] {
		// fmt.Println(item)
		c := ans[len(ans)-1]
		if c[1] >= item[0] {
			left := min(c[0], item[0])
			right := max(c[1], item[1])
			ans[len(ans)-1] = []int{left, right}
		} else {
			ans = append(ans, item)
		}
	}
	// fmt.Printf("%#v\n", intervals)
	return ans
}

func main() {
	// Test cases
	testCases := []struct {
		input    [][]int
		expected [][]int
	}{
		{
			input:    [][]int{{1, 3}, {2, 6}, {8, 10}, {15, 18}},
			expected: [][]int{{1, 6}, {8, 10}, {15, 18}},
		},
		{
			input:    [][]int{{1, 4}, {4, 5}},
			expected: [][]int{{1, 5}},
		},
		{
			input:    [][]int{{1, 4}, {0, 4}},
			expected: [][]int{{0, 4}},
		},
		{
			input:    [][]int{{1, 4}, {2, 3}},
			expected: [][]int{{1, 4}},
		},
		{
			input:    [][]int{{1, 4}, {0, 0}},
			expected: [][]int{{0, 0}, {1, 4}},
		},
	}

	for i, tc := range testCases {
		result := merge(tc.input)
		// Simple comparison
		_pass := len(result) == len(tc.expected)
		if _pass {
			for j := range result {
				if result[j][0] != tc.expected[j][0] || result[j][1] != tc.expected[j][1] {
					_pass = false
					break
				}
			}
		}
		if _pass {
			println("Test", i+1, "PASSED")
		} else {
			println("Test", i+1, "FAILED")
			println("  Input:", tc.input)
			println("  Expected:", tc.expected)
			println("  Got:", result)
		}
	}
}
