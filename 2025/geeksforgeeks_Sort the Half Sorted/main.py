import math


class Solution:
    def sortHalves(self, arr, n):
        # # 找分界点 k
        # k = n
        # for i in range(1, n):
        #     if arr[i] < arr[i - 1]:
        #         k = i
        #         break

        # Gap Method 合并 [0..k-1] 和 [k..n-1]
        gap = math.ceil(n / 2)
        while gap > 0:
            i = 0
            while i + gap < n:
                if arr[i] > arr[i + gap]:
                    arr[i], arr[i + gap] = arr[i + gap], arr[i]
                i += 1

            if gap == 1:
                break
            gap = math.ceil(gap / 2)


# 测试用例
Solution().sortHalves([4, 36, 95, 12, 12, 23, 34, 42, 65, 74], 10)
# Solution().sortHalves([22, 83, 17], 3)
# Solution().sortHalves([2, 3, 8, -1, 7, 10], 6)
# Solution().sortHalves([4, 6, 9, -5, -4, -3, -2, -1, 3], 9)
# Solution().sortHalves([25, 6, 28, 46, 59, 62, 63, 65, 79, 82], 10)


# # Solution().sortHalves([2, 3, 8, -1, 7, 10], 6)
# Solution().sortHalves([4, 6, 9, -5, -4, -3, -2, -1, 3], 9)
# Solution().sortHalves([25, 6, 28, 46, 59, 62, 63, 65, 79, 82], 10)
# #
