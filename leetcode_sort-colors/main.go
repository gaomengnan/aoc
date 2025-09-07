package main

import "fmt"

func main() {
	sample := []int{
		3, 1, 2, 3, 5,
	}
	ret := mergeSort(sample)
	fmt.Println(ret)
}

func mergeSort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}

	mid := len(arr) / 2
	fmt.Println("start-split", arr)

	left := mergeSort(arr[:mid])
	right := mergeSort(arr[mid:])

	return merge(left, right)
}

func merge(left, right []int) []int {
	fmt.Println("start-mege", left, right)
	res := make([]int, 0, len(left)+len(right))
	i, j := 0, 0

	for i < len(left) && j < len(right) {
		if left[i] <= right[j] {
			res = append(res, left[i])
			i++
		} else {
			res = append(res, right[j])
			j++
		}
	}
	res = append(res, left[i:]...)
	res = append(res, right[j:]...)
	fmt.Println("end-merge", res)
	return res
}
