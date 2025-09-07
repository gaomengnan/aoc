class Solution:
    def findSplit(self, arr):
        # Return an array of possible answer, driver code will judge and return true or false based on
        sums = sum(arr)
        divier = sums // 3
        # print(divier)

        prefix_sum = 0
        po = []
        for i in range(0, len(arr)):
            prefix_sum += arr[i]

            if prefix_sum == divier and len(po) < 2:
                po.append(i)
                prefix_sum = 0
                continue

        if len(po) < 2:
            return [-1, -1]
        return po


a = Solution()

# 测试用例 1（可以拆分）
print(a.findSplit([1, 2, 3, 0, 3]))  # 可能输出: [1, 3]

# 测试用例 2（可以拆分）
print(a.findSplit([0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1]))  # 可能输出: [3, 7]

# 测试用例 3（不可能拆分）
print(a.findSplit([1, 2, 3, 4, 5]))  # 输出: [-1, -1]

# 测试用例 4（全部零，可以多种拆分）
print(a.findSplit([0, 0, 0, 0]))  # 输出: [0, 1] 或 [1, 2]

# 测试用例 5（重复数）
print(a.findSplit([2, 2, 2, 2, 2, 2]))  # 输出: [1, 3] 或 [0, 2]

# 你的例子（可以拆分）
print(a.findSplit([1, 3, 4, 0, 4]))  # 输出: [1, 3]
