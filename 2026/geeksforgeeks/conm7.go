package main

import (
	"fmt"
)

func longestPalindrome(s string) string {
	if len(s) == 0 {
		return ""
	}
	start, end := 0, 0

	for i := 0; i < len(s); i++ {

		var curlen int
		l1 := expandAroundCenter(s, i, i)
		l2 := expandAroundCenter(s, i, i+1)

		curlen = l1
		if l2 > l1 {
			curlen = l2
		}

		if curlen > end-start+1 {
			start = i - (curlen-1)/2
			end = i + curlen/2
		}

	}
	return s[start : end-1]
}

// 从中心向两边扩展，返回最大回文长度
func expandAroundCenter(s string, left, right int) int {
	for left >= 0 && right < len(s) && s[left] == s[right] {
		left--
		right++

	}

	return right - left - 1
}

func main() {
	fmt.Println(longestPalindrome("babad")) // "bab" 或 "aba"
	fmt.Println(longestPalindrome("cbbd"))  // "bb"
	fmt.Println(longestPalindrome("a"))     // "a"
	fmt.Println(longestPalindrome("ac"))    // "a" 或 "c"
}
