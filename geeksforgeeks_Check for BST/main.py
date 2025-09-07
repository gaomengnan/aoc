from typing import Optional


class Node:
    def __init__(self, val: int):
        self.data = val
        self.left: Optional['Node'] = None
        self.right: Optional['Node'] = None


class Solution:
    def isBST(self, root: Optional[Node]) -> bool:
        if root is None:
            return True
        
        def helper(node: Optional[Node], low: float, height: float) -> bool:
            if node is None:
                return True
            if node.data <= low or node.data >= height:
                return False
            return helper(node.left, low, node.data) and helper(
                node.right, node.data, height
            )

        return helper(root, float("-inf"), float("inf"))


if __name__ == "__main__":
    # Example usage
    root = Node(10)
    root.left = Node(5)
    root.right = Node(15)
    root.left.left = Node(2)
    root.left.right = Node(7)
    
    solution = Solution()
    print(f"Is BST: {solution.isBST(root)}")  # Should print True
