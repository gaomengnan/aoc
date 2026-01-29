class Solution:
    def maxIndexDiff(self, arr):
        n = len(arr)

        # 构建 Left Min
        # Right Max
        LMin = [0] * n
        RMax = [0] * n

        LMin[0] = arr[0]

        for i in range(1, n):
            LMin[i] = min(arr[i], LMin[i - 1])

        print(LMin)

        RMax[n - 1] = arr[n - 1]
        for i in range(n - 2, -1, -1):
            RMax[i] = max(arr[i], RMax[i + 1])
        print(RMax)

        # 双指针扫描

        i = 0
        j = 0
        maxDiff = -1
        while i < n and j < n:
            if LMin[i] <= RMax[j]:
                maxDiff = max(maxDiff, j - i)
                j += 1
            else:
                i += 1
        return maxDiff


Solution().maxIndexDiff([34, 8, 10, 3, 2, 80, 30, 33, 1])
# 34 8 10
