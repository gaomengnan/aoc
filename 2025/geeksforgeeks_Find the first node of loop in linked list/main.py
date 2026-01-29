import sys, os

sys.path.append(os.path.dirname(os.path.dirname(__file__)))

from leetcode_utils import util


class Solution:
    def cycleStart(self, head):
        if not head or not head.next:
            return -1  # 空链表或单节点，不可能有环

        slow = head

        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if fast == slow:
                break
        else:
            return -1

        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next

        return slow


Solution().cycleStart(
    util.create_cyclic_linked_list([1, 2, 3, 4, 5], 2)
)
