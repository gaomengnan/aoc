package main

func main() {
	sample := generateListNode([]int{
		1, 2, 2, 1, 4, 1, 2, 3, 2, 5, 2, 1,
	})
	partition(sample, 3)
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

type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
	// dummy

	fast, slow := head, head
	//  1 2 2 1 1 2 4 3 2 5 2 1
	//  1 2 2 1 1 2 2  4 3 5 2 1
	//             ^    ^
	//
	//  1, 2, 2, 1, 4, 4, 1, 2, 3, 2, 5, 2, 1
	//  5 4 3 2
	//  2 5 4 3
	//  2 4 3 5
	//  2 3 4 5
	//  2 3 5 4
	//  4352
	//  2354kk

	// cur := head
	flags := false
	// var point *ListNode

	for fast != nil {
		fval := fast.Val
		if fval == x {
			flags = true
			// fast = fast.Next
		}

		if !flags {
			if fval < x {
				if slow.Val > x {
					t := slow
					pv := fval
					for t != nil {
						tv := t.Val
						t.Val = pv
						pv = tv
						t = t.Next
						if tv == fval {
							// fast.Val = x
							break
						}
					}
					slow = slow.Next
				} else {
					// slow = fast
					fast = fast.Next
					slow = slow.Next
				}
			}

			if fval > x {
				// slow = fast
				fast = fast.Next
			}
		} else {
			if fval < x {
				t := slow
				pv := fval
				for t != nil {
					tv := t.Val
					t.Val = pv
					pv = tv
					t = t.Next
					if tv == fval {
						// fast.Val = x
						break
					}
				}
				slow = slow.Next
			} else {
				fast = fast.Next
			}
		}
	}
	return nil
}
