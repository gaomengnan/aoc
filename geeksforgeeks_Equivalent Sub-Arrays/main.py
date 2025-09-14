from collections import Counter


class Solution:
    def countDistinctSubarray(self, arr, n):
        slow = 0
        fast = 0

        # 计算原数组中不同元素的个数
        a1 = Counter(arr)
        k = len(a1)

        # 记录当前窗口中元素的计数
        dp = Counter()

        # 结果变量，用于记录满足条件的子数组
        ans = 0

        while fast < n:
            # 将 fast 指针指向的元素加入窗口
            dp[arr[fast]] += 1

            # 如果当前窗口内的不同元素数量等于原数组的不同元素数量
            while len(dp) == k:
                # 统计所有符合条件的子数组
                ans += n - fast

                # 收缩窗口，缩小左边界 slow，保持窗口内不同元素的数量为 k
                dp[arr[slow]] -= 1
                if dp[arr[slow]] == 0:
                    del dp[arr[slow]]
                slow += 1

            fast += 1

        return ans


# Example usage
print(Solution().countDistinctSubarray([2, 1, 3, 2, 3], 5))  # Output should be 5
