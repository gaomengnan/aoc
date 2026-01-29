import unittest
from main import Solution


class TestClosestPair(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example_1(self):
        """Test case from README example 1"""
        arr1 = [1, 4, 5, 7]
        arr2 = [10, 20, 30, 40]
        x = 32
        result = self.solution.printClosest(arr1, arr2, len(arr1), len(arr2), x)
        self.assertEqual(result, [1, 30])

    def test_example_2(self):
        """Test case from README example 2"""
        arr1 = [1, 4, 5, 7]
        arr2 = [10, 20, 30, 40]
        x = 50
        result = self.solution.printClosest(arr1, arr2, len(arr1), len(arr2), x)
        self.assertEqual(result, [7, 40])

    def test_exact_match(self):
        """Test case where exact sum exists"""
        arr1 = [1, 2, 3]
        arr2 = [4, 5, 6]
        x = 7
        result = self.solution.printClosest(arr1, arr2, len(arr1), len(arr2), x)
        self.assertEqual(result, [1, 6])

    def test_single_element_arrays(self):
        """Test case with single element arrays"""
        arr1 = [5]
        arr2 = [10]
        x = 15
        result = self.solution.printClosest(arr1, arr2, len(arr1), len(arr2), x)
        self.assertEqual(result, [5, 10])

    def test_negative_numbers(self):
        """Test case with negative numbers"""
        arr1 = [-5, -2, 0, 3]
        arr2 = [-10, -5, 1, 8]
        x = -3
        result = self.solution.printClosest(arr1, arr2, len(arr1), len(arr2), x)
        self.assertEqual(result, [-5, 1])

    def test_zero_target(self):
        """Test case with zero target"""
        arr1 = [-3, -1, 2, 4]
        arr2 = [-2, 1, 3, 5]
        x = 0
        result = self.solution.printClosest(arr1, arr2, len(arr1), len(arr2), x)
        # Multiple pairs sum to 0: (-3,3), (-1,1), (2,-2)
        # Algorithm prefers pair with larger difference between elements
        self.assertEqual(result, [-3, 3])

    def test_large_numbers(self):
        """Test case with large numbers"""
        arr1 = [1000, 2000, 3000]
        arr2 = [4000, 5000, 6000]
        x = 7000
        result = self.solution.printClosest(arr1, arr2, len(arr1), len(arr2), x)
        self.assertEqual(result, [1000, 6000])

    def test_empty_arrays(self):
        """Test case with empty arrays"""
        arr1 = []
        arr2 = []
        x = 10
        result = self.solution.printClosest(arr1, arr2, len(arr1), len(arr2), x)
        self.assertEqual(result, [])

    def test_one_empty_array(self):
        """Test case with one empty array"""
        arr1 = [1, 2, 3]
        arr2 = []
        x = 5
        result = self.solution.printClosest(arr1, arr2, len(arr1), len(arr2), x)
        self.assertEqual(result, [])

    def test_duplicate_values(self):
        """Test case with duplicate values"""
        arr1 = [2, 2, 2, 5]
        arr2 = [3, 3, 7, 7]
        x = 5
        result = self.solution.printClosest(arr1, arr2, len(arr1), len(arr2), x)
        self.assertEqual(result, [2, 3])

    def test_multiple_solutions(self):
        """Test case where multiple pairs have same difference"""
        arr1 = [1, 3, 5]
        arr2 = [2, 4, 6]
        x = 7
        result = self.solution.printClosest(arr1, arr2, len(arr1), len(arr2), x)
        self.assertIn(result, [[1, 6], [3, 4]])

    def test_target_smaller_than_all_pairs(self):
        """Test case where target is smaller than all possible sums"""
        arr1 = [10, 20, 30]
        arr2 = [40, 50, 60]
        x = 5
        result = self.solution.printClosest(arr1, arr2, len(arr1), len(arr2), x)
        self.assertEqual(result, [10, 40])

    def test_target_larger_than_all_pairs(self):
        """Test case where target is larger than all possible sums"""
        arr1 = [1, 2, 3]
        arr2 = [4, 5, 6]
        x = 100
        result = self.solution.printClosest(arr1, arr2, len(arr1), len(arr2), x)
        self.assertEqual(result, [3, 6])


if __name__ == "__main__":
    unittest.main()
