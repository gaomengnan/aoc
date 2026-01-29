# User function Template for python3


class Solution:
    def getMinDiff(self, arr, k):
        arr.sort()
        ans = arr[-1] - arr[0]
        small = arr[0] + k
        large = arr[-1] - k

        for i in range(1, len(arr)):
            if arr[i] - k <= 0:
                continue
            cur_min = min(small, arr[i] - k)
            cur_max = max(large, arr[i - 1] + k)

            ans = min(ans, cur_max - cur_min)
        return ans


# print(Solution().getMinDiff([1, 5, 8, 10], 2))
# print(Solution().getMinDiff([3, 9, 12, 16, 20], 3)) # 17 13 9  ///   6 12/6jj
# print(Solution().getMinDiff([4, 6], 10))
print(Solution().getMinDiff([1, 10, 14, 14, 14, 15], 6))
# print(Solution().getMinDiff([1, 2, 3], 2))
