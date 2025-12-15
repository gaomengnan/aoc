package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// 解析字符串到整数的工具函数
func parseIntField(field string) (int, error) {
	return strconv.Atoi(field)
}

func main() {
	solve1()
	solve2()
}
func solve2() {
	f, err := os.Open("input.txt")

	if err != nil {
		panic(err)
	}

	scanner := bufio.NewScanner(f)
	var secure int
	for scanner.Scan() {
		text := scanner.Text()
		fields := strings.Fields(text)
		// fmt.Println(fields)

		var checkFieldsValid func([]string) bool

		checkFieldsValid = func(f []string) bool {
			var seqb string
			var failure bool
			for i := 0; i < len(f); i++ {
				// 0 1-1
				// 1 2-1
				// 2  3-1 [0 1 2]
				if i == len(f)-1 {
					continue
				}

				l, err := parseIntField(f[i])

				if err != nil {
					panic(err)
				}

				r, err := parseIntField(f[i+1])
				if err != nil {
					panic(err)
				}

				diffVal := r - l

				if diffVal == 0 {
					failure = true
					// goto Failure
					break
				}

				var currentSeq string

				if diffVal > 0 {
					currentSeq = "+"
				} else {
					currentSeq = "-"
				}

				if seqb != "" && seqb != currentSeq {
					failure = true
					break
				}
				// 判断是否相差  1-3 之间
				absVal := math.Abs(float64(diffVal))
				if absVal < 1 || absVal > 3 {
					failure = true
					// goto Failure
					break
				}
				seqb = currentSeq
				// secure++
			}
			return failure
		}

		if !checkFieldsValid(fields) {
			secure++
		} else {
			index := 0
			for index < len(fields) {
				result := make([]string, len(fields)-1)
				copy(result, fields[:index])
				copy(result[index:], fields[index+1:])
				checked := checkFieldsValid(result)
				if !checked {
					fmt.Printf("Slice is %#v, remove index = %d, after slice = %#v \n", fields, index, result)
					secure++
					break
				} else {
					index++
				}
			}
		}
	}
	fmt.Printf("Part-2 safe line count: %d \n", secure)
}

func solve1() {
	f, err := os.Open("input.txt")

	if err != nil {
		panic(err)
	}

	scanner := bufio.NewScanner(f)
	var secure int
	for scanner.Scan() {
		text := scanner.Text()
		fields := strings.Fields(text)
		// fmt.Println(fields)
		var seqb string
		var failure bool

		for i := 0; i < len(fields); i++ {
			// 0 1-1
			// 1 2-1
			// 2  3-1 [0 1 2]
			if i == len(fields)-1 {
				continue
			}

			l, err := parseIntField(fields[i])

			if err != nil {
				panic(err)
			}

			r, err := parseIntField(fields[i+1])
			if err != nil {
				panic(err)
			}

			diffVal := r - l

			if diffVal == 0 {
				failure = true
				break
			}

			var currentSeq string

			if diffVal > 0 {
				currentSeq = "+"
			} else {
				currentSeq = "-"
			}

			if seqb != "" && seqb != currentSeq {
				failure = true
				break
			}
			// 判断是否相差  1-3 之间
			absVal := math.Abs(float64(diffVal))
			if absVal < 1 || absVal > 3 {
				failure = true
				break
			}
			seqb = currentSeq
			// secure++
		}

		if !failure {
			secure++
		}
	}
	fmt.Printf("Part-1 safe line count: %d \n", secure)
}
