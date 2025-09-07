import unittest
from main import Solution


class TestPairsWithDifferenceK(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_basic_case(self):
        """Test basic case from the example"""
        arr = [1, 1, 1, 4, 5, 6]
        k = 7
        result = self.solution.countPairs(arr, k)
        self.assertEqual(result, 0)  # (1,6), (1,6), (1,6)

    def test_no_pairs(self):
        """Test case where no pairs exist"""
        arr = [1, 2, 3, 4]
        k = 10
        result = self.solution.countPairs(arr, k)
        self.assertEqual(result, 0)

    def test_single_element(self):
        """Test case with single element"""
        arr = [5]
        k = 3
        result = self.solution.countPairs(arr, k)
        self.assertEqual(result, 0)

    def test_duplicate_elements(self):
        """Test case with duplicate elements"""
        arr = [2, 2, 2, 2]
        k = 0
        result = self.solution.countPairs(arr, k)
        self.assertEqual(result, 12)  # Each 2 pairs with itself

    def test_negative_difference(self):
        """Test case with negative k (should work same as positive)"""
        arr = [1, 2, 3, 4]
        k = -1
        result = self.solution.countPairs(arr, k)
        self.assertEqual(result, 3)

    def test_zero_difference(self):
        """Test case with k=0"""
        arr = [1, 2, 2, 3, 3, 3]
        k = 0
        result = self.solution.countPairs(arr, k)
        self.assertEqual(result, 8)  # (2,2), (3,3), (3,3), (3,3)

    def test_large_numbers(self):
        """Test case with large numbers"""
        arr = [100, 200, 300, 400]
        k = 100
        result = self.solution.countPairs(arr, k)
        self.assertEqual(result, 3)  # (100,200), (200,300), (300,400)

    def test_mixed_numbers(self):
        """Test case with mixed positive numbers"""
        arr = [1, 5, 3, 4, 2]
        k = 2
        result = self.solution.countPairs(arr, k)
        self.assertEqual(result, 3)  # (1,3), (3,5), (2,4)

    def test_empty_array(self):
        """Test case with empty array"""
        arr = []
        k = 5
        result = self.solution.countPairs(arr, k)
        self.assertEqual(result, 0)

    def test_all_same_elements(self):
        """Test case where all elements are the same"""
        arr = [7, 7, 7, 7, 7]
        k = 0
        result = self.solution.countPairs(arr, k)
        self.assertEqual(result, 20)  # Each element pairs with itself


if __name__ == "__main__":
    unittest.main()
