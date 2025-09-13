class Solution:
    def minDifference(self, N, A):
        # 前缀和
        pre_sum = [0] * N
        pre_sum[0] = A[0]
        for i in range(1, N):
            pre_sum[i] = A[i] + pre_sum[i - 1]
        min_diff = float('inf')

        print(pre_sum)


Solution().minDifference(5, [4, 2, 2, 5, 1])
