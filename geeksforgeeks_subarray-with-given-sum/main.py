class Solution:
    def subarraySum(self, arr, target):
        start = 0
        current_sum = 0

        for end in range(len(arr)):
            current_sum += arr[end]

            # 当窗口和超过 target，缩小窗口直到不超过
            while current_sum > target and start <= end:
                current_sum -= arr[start]
                start += 1

            # 找到目标和，返回 1-based 索引
            if current_sum == target:
                return [start + 1, end + 1]

        return [-1]


a = Solution()
sample = [19, 23, 15, 6, 6, 2, 28, 2]
ret = a.subarraySum(sample, 29)
print(ret)
