# Given an array of integers and a target sum, determine if there exists a triplet in the array that sums up to the target.
# Example:
# Input: arr = [1, 4, 45, 6, 10, 8], target = 13
# Output: True (because 1 + 4 + 8 = 13)
# Input: arr = [1, 2, 3, 4, 5], target = 20
# Output: False (no triplet sums to 20)
# Constraints:
# - The array can contain both positive and negative integers.
# - The array can have duplicates.
# Approach:
# 1. Sort the array.
# 2. Iterate through each element, treating it as the first element of the triplet
# 3. Use two pointers to find the other two elements that sum up to the target
# minus the first element.
# Time Complexity: O(n^2) due to the nested loop structure.
# Space Complexity: O(1) since we are not using any additional data structures
# that grow with input size.
class Solution:
    def hasTripletSum(self, arr, target):
        # 1 3 6 8 10 45
        arr = sorted(arr)
        n = len(arr)
        i = 0

        while i < len(arr):
            left, right = i + 1, n - 1
            while left < right:
                # left, right = i + 1, n - 1
                genSum = arr[i] + arr[left] + arr[right]

                if genSum == target:
                    return True

                if genSum > target:
                    right -= 1
                else:
                    left += 1
            i += 1

        return False


a = Solution()
print(a.hasTripletSum([1, 4, 45, 6, 10, 8], 13))  # Example usage
