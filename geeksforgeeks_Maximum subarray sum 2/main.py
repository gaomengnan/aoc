class Solution:
    def maxSubarrSum(self, arr, a, b):
        i = 0
        j = 0

        window_sum = 0
        MAX = float("-inf")

        while j < len(arr):
            window_sum += arr[j]

            steps = j - i + 1

            if steps >= a and steps <= b:
                MAX = max(MAX, window_sum)

            if steps == b:
                window_sum -= arr[i]
                i += 1
                MAX = max(MAX, window_sum)
            j += 1

        return MAX


# print(Solution().maxSubarrSum([-1, 3, -1, -2, 5, 3, -5, 2, 2], 3, 5))
# print(Solution().maxSubarrSum([4, 5, -1, -2, 6], 2, 4))
print(Solution().maxSubarrSum([-8, -9, 5, 2, 10, -3], 1, 5))
