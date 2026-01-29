package main

import "fmt"

func main() {
	fmt.Println("hello")
	sample := []int{
		4, 5, 6, 6, 7, 8, 9, 10, 11, 3,
	}
	search(sample, 3)
}

// func search(nums []int, target int) bool {
//     for i :=  range nums {
//         if nums[i] == target {
//             return  true
//         }
//     }
//     return false
// }

func search(nums []int, target int) (sg bool) {
	// [2,5,6,0,0,1,2]
	// [0 0 1 2 2 5 6]
	left, right := 0, len(nums)-1
	head, tail := nums[0], nums[len(nums)-1]

	var bs func(left, right int)

	bs = func(left, right int) {
		for left <= right {
			mid := left + (right-left)/2
			fmt.Println("mid", mid)

			if nums[mid] == target {
				sg = true
				return
			}

			if head < nums[mid] {
				if nums[mid] < target {
					left = mid + 1
					return
				}
			}

			if tail > nums[mid] {
				if nums[mid] < target {
					right = mid - 1
					return
				}
			}

			// 左边
			bs(left, mid-1)
			// 右边
			bs(mid+1, right)
		}
	}

	bs(0, len(nums)-1)

	return
}
