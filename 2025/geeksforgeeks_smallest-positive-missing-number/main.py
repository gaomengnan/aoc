class Solution:
    def firstMissingPositive(self, nums):
        n = len(nums)
        for i in range(n):
            while nums[i] > 0 and nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1
    
a = Solution
print(a.firstMissingPositive(a, [3, 4, -1, 1]))  # Output: 2
print(a.firstMissingPositive(a, [1, 2, 0]))       # Output: 3
print(a.firstMissingPositive(a, [7, 8, 9, 11, 12]))  # Output: 1
print(a.firstMissingPositive(a, [1, 2, 3, 4, 5]))  # Output: 6
print(a.firstMissingPositive(a, [-1, -2, -3]))  # Output: 1
# Example usage:
print(a.firstMissingPositive(a, [2, 3, 7, 6, 8, -1, -10, 15]))  # Output: 1
print(a.firstMissingPositive(a, [1, 1, 0, -1, -2                ]))  # Output: 2    