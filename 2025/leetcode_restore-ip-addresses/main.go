package main

import (
	"fmt"
	"strings"
)

func main() {
	sample := "25525511135"
	restoreIpAddresses(sample)
}

func restoreIpAddresses(s string) []string {
	// n := len(s)

	// res := (n + 4 - 1) / 4
	// fmt.Println(res)

	runes := []rune(s)

	var backstack func(path []string, left int, leftstr []rune)

	ret := make([]string, 0)

	backstack = func(path []string, left int, leftstr []rune) {
		nextl := left - 1

		leng := len(leftstr)

		if len(path) == 4 && left == 0 && leng == 0 {
			// fmt.Println("path", path)
			tmp := make([]string, len(path))
			copy(tmp, path)

			ret = append(ret, strings.Join(tmp, "."))
		}

		if nextl < 0 {
			return
		}

		// fmt.Println("path", path)
		for i := 1; i <= 3; i++ {
			maxCols := 0
			if nextl > 0 {
				maxCols = ((leng - i) + nextl - 1) / nextl
			}

			// fmt.Println("nextl", nextl)
			// fmt.Println("len", leng)

			// fmt.Println("max-col", maxCols)

			if i > leng {
				break
			}

			letters := leftstr[:i]

			muliter := 1
			sum := 0
			for i := len(letters) - 1; i >= 0; i-- {
				sum += int(letters[i]-'0') * muliter
				muliter *= 10
			}

			// fmt.Println("sum", sum)

			if maxCols >= 0 && maxCols <= 3 && sum <= 1<<8-1 {
				// fmt.Println("todo")
				// res := leftstr[i:]
				// fmt.Println("res", res)

				path = append(path, string(letters))

				backstack(path, nextl, leftstr[i:])

				path = path[:len(path)-1]
			}

			if sum == 0 {
				break
			}
		}
	}

	backstack([]string{}, 4, runes)

	fmt.Println("ret", ret)

	return nil
}
