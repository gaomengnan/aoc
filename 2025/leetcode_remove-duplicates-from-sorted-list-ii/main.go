package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func generateListNode(sample []int) *ListNode {
	dummy := &ListNode{}
	cur := dummy

	for _, v := range sample {
		cur.Next = &ListNode{Val: v}
		cur = cur.Next
	}

	return dummy.Next
}

func main() {
	head := generateListNode([]int{
		1, 2, 3, 3, 4, 4, 5,
	})
	fmt.Println("head", head)
	deleteDuplicates(head)
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 输入：head = [1,2,3,3,4,4,5]

func deleteDuplicates(head *ListNode) *ListNode {
	dummy := &ListNode{}
	cur := dummy
	tmp := head
	prev := -200

	for tmp != nil {
		cval := tmp.Val

		nval := -200
		if tmp.Next != nil {
			nval = tmp.Next.Val
		}

		if cval != prev && cval != nval {
			cur.Next = &ListNode{
				Val: cval,
			}
			cur = cur.Next
		}

		prev = cval

		tmp = tmp.Next
	}

	return dummy.Next
}
