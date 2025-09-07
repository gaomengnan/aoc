import unittest
from main import Solution


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example_case(self):
        # Test case based on problem description
        arr = [1, 2, 3]
        # After sorting: [1, 2, 3]
        # 1 + 2 = 3, so should return True
        self.assertTrue(self.solution.findTriplet(arr))

    def test_negative_numbers(self):
        arr = [-3, -1, 2]
        # After sorting: [-3, -1, 2]
        # -1 + 2 = 1 (not in array)
        # -3 + (-1) = -4 (not in array)
        # -3 + 2 = -1 (in array)
        self.assertFalse(self.solution.findTriplet(arr))

    def test_no_triplet(self):
        arr = [1, 2, 4]
        # After sorting: [1, 2, 4]
        # 1 + 2 = 3 (not in array)
        # 1 + 4 = 5 (not in array)
        # 2 + 4 = 6 (not in array)
        self.assertFalse(self.solution.findTriplet(arr))

    def test_all_zeros(self):
        arr = [0, 0, 0]
        # After sorting: [0, 0, 0]
        # 0 + 0 = 0 (in array)
        self.assertTrue(self.solution.findTriplet(arr))

    def test_duplicates(self):
        arr = [1, 1, 2]
        # After sorting: [1, 1, 2]
        # 1 + 1 = 2 (in array)
        self.assertTrue(self.solution.findTriplet(arr))

    def test_larger_array_with_triplet(self):
        arr = [1, 2, 3, 4, 5, 6]
        # After sorting: [1, 2, 3, 4, 5, 6]
        # Multiple triplets exist: 1+2=3, 1+3=4, 1+4=5, 1+5=6, 2+3=5, 2+4=6
        self.assertTrue(self.solution.findTriplet(arr))

    def test_larger_array_without_triplet(self):
        arr = [1, 3, 5, 7, 9]
        # After sorting: [1, 3, 5, 7, 9]
        # No triplets exist
        self.assertFalse(self.solution.findTriplet(arr))


if __name__ == "__main__":
    unittest.main()
