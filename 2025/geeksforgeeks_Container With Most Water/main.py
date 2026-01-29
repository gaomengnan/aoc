class Solution:
    def maxWater(self, arr):
        n = len(arr)
        ans = 0
        s, f = 0, n - 1

        while s < f:
            ans = max(ans, (f - s) * min(arr[s], arr[f]))

            if arr[s] < arr[f]:
                s += 1
            else:
                f -= 1

        return ans


print(Solution().maxWater([7, 3, 10, 1, 6, 6, 2, 1, 2]))
# print(Solution().maxWater([1, 5, 4, 3]))
# print(Solution().maxWater([1, 8, 6, 2, 5, 4, 8, 3, 7]))
# print(Solution().maxWater([4, 3, 2, 1, 4]))
# print(Solution().maxWater([2, 3, 10, 5, 7, 8, 9]))
# print(Solution().maxWater([5]))
# print(Solution().maxWater([0, 0, 0, 0]))
# print(Solution().maxWater([2, 2, 2, 2]))
# print(Solution().maxWater([10000, 1, 10000]))


#  4 + 3 + 3 + 3

# 2, 1, 8, 6, 4, 6, 5, 5
#
#
