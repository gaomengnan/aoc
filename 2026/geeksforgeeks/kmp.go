package main

import (
	"fmt"
)

func buildNext(s string) []int {
	n := len(s)

	next := make([]int, n)
	j := 0

	for i := 1; i < n; i++ {
		for j > 0 && s[j] != s[i] {
			j = next[j-1]
		}

		if s[j] == s[i] {
			j++
		}

		next[i] = j
	}

	return next
}

func kmpSearch(text, pattern string) int {
	n, m := len(text), len(pattern)
	if m == 0 {
		return 0
	}

	if n == 0 || n < m {
		return 0
	}

	prefs := buildNext(pattern)

	j := 0

	for i := 0; i < n; i++ {
		for j > 0 && text[i] != pattern[j] {
			j = prefs[j-1]
		}

		if text[i] == pattern[j] {
			j++
		}

		if j == m {
			return i - m + 1
		}
	}
	return -1
}

func main() {
	reg := kmpSearch("ababcabcacbab", "abcac")
	fmt.Println(reg)
}
