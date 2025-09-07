package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strconv"
	"strings"
)

// 解析字符串到整数的工具函数
func parseIntField(field string) (int, error) {
	return strconv.Atoi(field)
}

func main() {
	// part1()
	part2()
}

func part1() {
	scanner := bufio.NewScanner(os.Stdin)
	var total int
	// part 1
	for scanner.Scan() {
		txt := scanner.Text()
		pattern := `mul\((\d+),(\d+)\)`
		re := regexp.MustCompile(pattern)
		ret := re.FindAllStringSubmatch(txt, -1)

		for _, m := range ret {
			l, err := parseIntField(m[1])
			if err != nil {
				continue
			}
			r, err := parseIntField(m[2])

			if err != nil {
				continue
			}
			total += l * r
		}
	}
	fmt.Printf("Total is : %d", total)
}

func part2() {
	// file, err := os.Open("input-2.txt")
	// if err != nil {
	// 	fmt.Println("无法打开文件:", err)
	// 	return
	// }
	// defer file.Close()
	scanner := bufio.NewScanner(os.Stdin)
	var total int
	var hasDont = false
	for scanner.Scan() {
		txt := scanner.Text()
		pattern := `(?:mul\((\d+),(\d+)\))|(do\(\)|don't\(\))`
		re := regexp.MustCompile(pattern)
		matches := re.FindAllStringSubmatch(txt, -1)

		//  2 * 4 +  8 * 5
		for _, mh := range matches {
			fmt.Println(mh[0])
			if strings.Contains(mh[0], "don't()") {
				hasDont = true
			} else if strings.Contains(mh[0], "do()") {
				hasDont = false
				continue
			}
			if hasDont {
				fmt.Printf("Dont Before is %v \n", mh[0])
				continue
			}

			l, err := parseIntField(mh[1])
			if err != nil {
				continue
			}

			r, err := parseIntField(mh[2])
			if err != nil {
				continue
			}
			total += l * r
			// fmt.Printf("%v * %v \n", l, r)
		}
	}
	// fmt.Printf("Expression is : %s \n", strings.TrimSuffix(expression, "+ "))
	fmt.Printf("Total is : %d \n", total)
}
