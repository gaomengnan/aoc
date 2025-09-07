class Solution:
    def maxWater(self, arr):
        n = len(arr)
        left_max = [0] * n
        right_max = [0] * n

        total = 0

        left_max[0] = arr[0]
        for i in range(1, n):
            left_max[i] = max(left_max[i - 1], arr[i])

        right_max[n - 1] = arr[-1]

        for i in range(n - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], arr[i])

        print(left_max)

        for i in range(0, n):
            total += max(0, min(left_max[i], right_max[i]) - arr[i])

        return total


a = Solution()
a.maxWater([1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])
