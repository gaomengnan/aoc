class Solution:
    def totalElements(self, arr):
        n = len(arr)

        i, j = 0, 0

        wd = {}

        # counter = 0

        ans = 0

        while j < n:
            wd[arr[j]] = wd.get(arr[j], 0) + 1

            while len(wd) > 2:
                wd[arr[i]] -= 1
                if wd[arr[i]] == 0:
                    del wd[arr[i]]
                i += 1

            ans = max(ans, j - i + 1)

            # print(ans)

            j += 1

        return ans


solution = Solution()

# 1. 普通情况，混合多个整数
print(solution.totalElements([1, 2, 1, 2, 3, 2, 2]))  # 输出 4
# 2. 全部相同元素
print(solution.totalElements([5, 5, 5, 5, 5]))  # 输出 5

# 3. 数组长度为1
print(solution.totalElements([10]))  # 输出 1

# 4. 数组长度为2，不同元素
print(solution.totalElements([7, 8]))  # 输出 2

# 5. 数组长度为2，相同元素
print(solution.totalElements([9, 9]))  # 输出 2

# 6. 数组长度大于2，连续两个元素不同
print(solution.totalElements([1, 2, 3, 4, 5, 6]))  # 输出 2 -> 任何连续两个元素

# 7. 长子数组在中间
print(solution.totalElements([1, 2, 1, 3, 3, 3, 2, 2]))  # 输出 5 -> [1,3,3,3,2]

# 8. 长子数组在开头
print(solution.totalElements([4, 4, 5, 5, 5, 6, 7]))  # 输出 5 -> [4,4,5,5,5]

# 9. 长子数组在结尾
print(solution.totalElements([1, 1, 2, 2, 2]))  # 输出 5 -> [1,1,2,2,2]

# 10. 多次切换两种元素
print(
    solution.totalElements([1, 2, 1, 2, 1, 2, 1, 2, 3])
)  # 输出 8 -> [1,2,1,2,1,2,1,2]
