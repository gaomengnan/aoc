package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
	"time"
)

func main() {
	solve1()
	solve2()
}

func solve2() {
	f, err := os.Open("input.txt")
	defer f.Close()

	if err != nil {
		panic(err)
	}

	scanner := bufio.NewScanner(f)
	var left []int
	var right []int
	var sum int

	for scanner.Scan() {
		content := scanner.Text()

		sp := strings.Split(content, "\r\n")
		for _, item := range sp {
			ret := strings.Fields(item)
			l, err := strconv.Atoi(ret[0])
			if err != nil {
				fmt.Println("Error parsing input:", err)
				return
			}
			r, err := strconv.Atoi(ret[1])
			if err != nil {
				fmt.Println("Error parsing input:", err)
				return
			}
			left = append(left, l)
			right = append(right, r)
		}
	}
	// fmt.Println(left)
	sort.Ints(left)
	sort.Ints(right)
	for i := 0; i < len(left); i++ {
		j := 0

		c := left[i]

		counter := 0

		// fmt.Printf("Current Diff Value is %d \n", i)

		for j <= len(right)-1 {
			// fmt.Printf("J = %d \n", j)
			time.Sleep(time.Duration(2))
			if right[j] < c {
				j++
				continue
			}
			if right[j] > c {
				break
			}

			if c == right[j] {
				counter++
				j++
			}
		}
		sum += c * counter
	}
	fmt.Printf("Part-2 Sum Of %d \n", sum)
}

func solve1() {
	scanner := bufio.NewScanner(os.Stdin)
	var left []int
	var right []int
	var sum float64

	for scanner.Scan() {
		content := scanner.Text()

		sp := strings.Split(content, "\r\n")
		for _, item := range sp {
			ret := strings.Fields(item)
			l, err := strconv.Atoi(ret[0])
			if err != nil {
				fmt.Println("Error parsing input:", err)
				return
			}
			r, err := strconv.Atoi(ret[1])
			if err != nil {
				fmt.Println("Error parsing input:", err)
				return
			}
			left = append(left, l)
			right = append(right, r)
		}
	}
	// fmt.Println(left)
	sort.Ints(left)
	sort.Ints(right)
	for i := 0; i < len(left); i++ {
		// fmt.Printf("%d %d\n", left[i], right[i])
		diff := right[i] - left[i]
		sum += math.Abs(float64(diff))
	}
	fmt.Printf("Part-1 Sum Of %f \n", sum)
}
