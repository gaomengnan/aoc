from collections import deque


class Solution:
    def shortestRange(self, root):
        if not root:
            return []

        res = []
        q = deque([root])

        while q:
            level = []

            for i in range(len(q)):
                node = q.popleft()
                level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            res.append(level)
