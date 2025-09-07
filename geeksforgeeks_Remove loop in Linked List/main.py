# node class:

class Node:
    def __init__(self, val):
        self.next = None
        self.data = val


class Solution:
    def removeLoop(self, head):
        # code here
        slow = head
        fast = head
        found = False

        while True:
            if not fast.next or not fast.next.next:
                break

            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                found = True

                break

        if found:
            slow = head

            while slow != fast:
                slow = slow.next
                fast = fast.next

            while fast.next != slow:
                fast = fast.next
            fast.next = None

            # print("true")
        else:
            pass
            # print("false")
