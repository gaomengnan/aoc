class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def generate_linked_list(values):
    """
    根据列表 values 生成链表，返回头节点
    """
    if not values:
        return None

    head = Node(values[0])
    current = head
    for val in values[1:]:
        current.next = Node(val)
        current = current.next
    return head


class Solution:
    def addTwoLists(self, head1, head2):
        a = []
        b = []

        a1 = head1

        while a1:
            a.append(a1.data)
            a1 = a1.next
        b1 = head2

        while b1:
            b.append(b1.data)

            b1 = b1.next
        i, j = len(a) - 1, len(b) - 1

        ans = []

        carry = 0
        while 0 <= i < len(a) or 0 <= j < len(b):
            v1 = a[i] if 0 <= i < len(a) else 0
            v2 = b[j] if 0 <= j < len(b) else 0

            smer = v1 + v2 + carry
            carry = smer // 10
            ans.append(smer % 10)

            i -= 1
            j -= 1

        if carry > 0:
            ans.append(carry)

        ans.reverse()

        head = None
        current = head

        for i in range(len(ans)):
            if ans[i] == 0 and head is None:
                continue
            elif head is None:
                head = Node(ans[i])
                current = head
            else:
                current.next = Node(ans[i])
                current = current.next

        # node1 = generate_linked_list(ans)

        cur = head

        while cur:
            print(cur.data)
            cur = cur.next

        print(a, b, ans, head)


h1 = generate_linked_list([0, 0, 0, 2, 3, 7, 1])
h2 = generate_linked_list([0, 0, 3, 1, 1, 2])

Solution().addTwoLists(h1, h2)
