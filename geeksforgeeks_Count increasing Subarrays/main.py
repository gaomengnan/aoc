class Solution:
    def countIncreasing(self, arr):
        n = len(arr)
        if n == 1:
            return 0

        slow = 0
        fast = 0
        ans = 0

        while fast < n:
            if arr[fast] - arr[fast - 1] <= 0:
                ans += (fast - 1 - slow + 1) * (fast - 1 - slow) // 2
                slow = fast

            fast += 1

        if fast != slow:
            ans += (fast - 1 - slow + 1) * (fast - 1 - slow) // 2
        return ans


# Constraints:
# 1 <= arr.size() <= 106
# 1 <= arri <= 107
print(Solution().countIncreasing([1, 5]))  # Expected: 1
print(Solution().countIncreasing([1, 3, 3, 2, 3, 5]))  # Expected: 4
print(Solution().countIncreasing([1, 2, 3, 4, 5]))  # Expected: 10
print(Solution().countIncreasing([5, 4, 3, 2, 1]))  # Expected: 0
print(Solution().countIncreasing([1]))  # Expected: 0
print(Solution().countIncreasing([1, 1, 1]))  # Expected: 0
print(Solution().countIncreasing([1, 2, 2, 4]))  # Expected: 2
