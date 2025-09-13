class Solution:
    def findMaxSubarraySum(self, arr, x):
        n = len(arr)
        slow = 0
        cur_sum = 0
        ans = 0

        for fast in range(n):
            cur_sum += arr[fast]

            # 窗口太大就缩小
            while cur_sum > x and slow <= fast:
                cur_sum -= arr[slow]
                slow += 1

            ans = max(ans, cur_sum)
            if ans == x:  # 提前返回
                return x

        return ans


# 测试
print(Solution().findMaxSubarraySum([16, 35, 33], 2))
print(Solution().findMaxSubarraySum([46, 22, 71, 76, 19], 73))
print(Solution().findMaxSubarraySum([2, 4, 6, 8, 10], 7))
print(Solution().findMaxSubarraySum([1, 2, 3, 4, 5], 11))
