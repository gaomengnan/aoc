package main

import "fmt"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {
	// 1 1
	// 2 2
	// 3 5
	// 4 14    ---5
	// 5 42  ----14
	res := generateTrees(6)
	// counter := 0
	// for _, item := range res {
	// 	fmt.Println(item.Val)
	// 	counter++
	// }

	countMap := make(map[int]int)
	for _, num := range res {
		countMap[num.Val]++
	}

	// 打印结果
	for k, v := range countMap {
		fmt.Printf("%d 出现了 %d 次\n", k, v)
	}
	// fmt.Println("counter", counter)
	fmt.Println(res)
}

// 左右子树也必须分别是 BST
func generateTrees(n int) []*TreeNode {
	if n == 0 {
		return []*TreeNode{}
	}
	return build(1, n)
}

var memo map[[2]int][]*TreeNode

func build(start, end int) []*TreeNode {
	if start > end {
		return []*TreeNode{nil}
	}

	res := []*TreeNode{}
	for i := start; i <= end; i++ {
		leftTrees := build(start, i-1)
		rightTrees := build(i+1, end)

		for _, l := range leftTrees {
			for _, r := range rightTrees {
				root := &TreeNode{i, l, r}
				res = append(res, root)
			}
		}
	}
	return res
}
