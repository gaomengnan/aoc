class Solution:
    # 线性查询
    def countOnes1(self, arr):
        res = 0

        for i in range(0, len(arr)):
            if arr[i] == 1:
                res += 1
        return res

    # 二分
    def countOnes(self, arr):
        n = len(arr)
        left = 0
        right = n - 1

        res = 0

        while left <= right:
            mid = left + (right - left) // 2
            if arr[mid] == 1:
                # 左边都是
                res += mid - left + 1
                left = mid + 1

            if arr[mid] == 0:
                # 需要往左边继续找
                right = mid - 1

        return res


a = Solution()
print(a.countOnes([1, 1, 1, 0, 0, 0]))  # Output: 3
print(a.countOnes([0, 0, 0, 0]))  # Output: 0
print(a.countOnes([1, 1, 1, 1]))  # Output: 4
print(a.countOnes([1, 1, 0, 0, 0, 0]))  # Output: 2
print(a.countOnes([1, 0]))  # Output: 1
print(a.countOnes([0]))  # Output: 0
print(a.countOnes([1]))  # Output: 1
print(a.countOnes([1, 1, 1, 1, 1, 0, 0, 0]))
