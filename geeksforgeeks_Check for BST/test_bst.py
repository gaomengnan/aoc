import unittest
from main import Node, Solution


class TestBST(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()
    
    def test_empty_tree(self):
        self.assertTrue(self.solution.isBST(None))
    
    def test_single_node(self):
        root = Node(10)
        self.assertTrue(self.solution.isBST(root))
    
    def test_valid_bst(self):
        root = Node(10)
        root.left = Node(5)
        root.right = Node(15)
        root.left.left = Node(2)
        root.left.right = Node(7)
        root.right.left = Node(12)
        root.right.right = Node(20)
        self.assertTrue(self.solution.isBST(root))
    
    def test_invalid_bst_left_violation(self):
        root = Node(10)
        root.left = Node(15)  # 15 > 10, violates BST
        root.right = Node(20)
        self.assertFalse(self.solution.isBST(root))
    
    def test_invalid_bst_right_violation(self):
        root = Node(10)
        root.left = Node(5)
        root.right = Node(8)   # 8 < 10, violates BST
        self.assertFalse(self.solution.isBST(root))
    
    def test_invalid_bst_deep_violation(self):
        root = Node(10)
        root.left = Node(5)
        root.right = Node(15)
        root.left.left = Node(2)
        root.left.right = Node(12)  # 12 > 10, violates BST
        self.assertFalse(self.solution.isBST(root))
    
    def test_duplicate_values(self):
        root = Node(10)
        root.left = Node(10)  # Duplicate value, violates BST
        self.assertFalse(self.solution.isBST(root))
    
    def test_left_skewed_tree(self):
        root = Node(10)
        root.left = Node(8)
        root.left.left = Node(6)
        root.left.left.left = Node(4)
        self.assertTrue(self.solution.isBST(root))
    
    def test_right_skewed_tree(self):
        root = Node(10)
        root.right = Node(12)
        root.right.right = Node(14)
        root.right.right.right = Node(16)
        self.assertTrue(self.solution.isBST(root))


if __name__ == '__main__':
    unittest.main()