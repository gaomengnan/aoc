class Solution:
    def minRemovals(self, arr, k):
        n = len(arr)
        target = sum(arr) - k

        i = 0
        j = 0
        pre_sum = 0

        ans = float("inf")

        while j < n:
            pre_sum = arr[j] + pre_sum
            # pre_sum = tot
            if pre_sum == target:
                ans = min(ans, i + (n - j - 1))
                # i += 1
                j += 1
                # break
            elif pre_sum > target:
                pre_sum -= arr[i]
                pre_sum -= arr[j]
                i += 1
            else:
                j += 1

        return ans


print(Solution().minRemovals([5, 3, 4, 6, 2], 6))
# print(Solution().minRemovals([3, 4, 1, 3, 2], 5))
# print(Solution().minRemovals([1, 1, 3, 1, 2], 4))
# print(Solution().minRemovals([1, 1, 3, 1, 10], 10))
