from typing import Optional


from typing import List


# Definition for singly Link List Node
class Node:
    def __init__(self, x):
        self.data = x
        self.next = None
        self.prev = None


# You can also use the following for printing the link list.
# displayList(node)
# """
# 生成一个双向链表
def generate_linked_list(values: List[int]) -> Optional[Node]:
    if not values:
        return None

    head = Node(values[0])
    current = head
    for value in values[1:]:
        new_node = Node(value)
        current.next = new_node
        new_node.prev = current
        current = new_node

    return head


class Solution:
    def findPairsWithGivenSum(
        self, target: int, head: Optional["Node"]
    ) -> List[List[int]]:
        starter = head
        tail = head

        while tail.next:
            tail = tail.next

        ans = []

        while starter.data < tail.data:
            toSum = starter.data + tail.data

            if toSum == target:
                ans.append([starter.data, tail.data])
                starter = starter.next
                tail = tail.prev
            elif toSum < target:
                starter = starter.next
            else:
                tail = tail.prev
        print(ans)
        return ans


Solution().findPairsWithGivenSum(10, generate_linked_list([1, 2, 3, 4, 5, 6, 7, 8, 9]))
