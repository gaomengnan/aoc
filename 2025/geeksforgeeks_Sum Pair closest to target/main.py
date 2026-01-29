class Solution:
    def sumClosest(self, arr, target):
        arr = sorted(arr)
        n = len(arr)

        left = 0
        right = n - 1
        if n == 1:
            return []

        ans = []
        bestDiff = float("inf")

        while left < right:
            currentSum = arr[left] + arr[right]
            currentDiff = abs(target - currentSum)

            if len(ans) == 0:
                ans = [arr[left], arr[right]]
                bestDiff = currentDiff
            else:
                if currentDiff < bestDiff or (
                    currentDiff == bestDiff and arr[right] - arr[left] > ans[1] - ans[0]
                ):
                    ans = [arr[left], arr[right]]
                    bestDiff = currentDiff

            if currentSum == target:
                return ans
            elif currentSum > target:
                right -= 1
            else:
                left += 1

        return ans


# Test cases
print(Solution().sumClosest([10, 30, 20, 5], 25))  # Example usage
print(Solution().sumClosest([1, 2, 3, 4, 5], 10))  # Target equals sum of largest pair
print(Solution().sumClosest([1, 2, 3, 4, 5], 1))  # Target less than smallest pair
print(Solution().sumClosest([1, 2, 3, 4, 5], 9))  # Target close to largest pair
print(Solution().sumClosest([1, 1, 1, 1], 2))  # All elements same
print(Solution().sumClosest([-1, 2, 1, -4], 1))  # Negative numbers
print(Solution().sumClosest([5], 10))  # Single element (should return [])
print(Solution().sumClosest([1, 3, 5, 7, 9], 6))  # Multiple pairs with same difference
