class Solution:
    def smallestSubWithSum(self, x, arr):
        n = len(arr)

        k = 0
        i = 0
        pre_sum = 0

        ans = float("inf")

        while i < n:
            if arr[i] + pre_sum > x:
                ans = min(ans, i - k + 1)
                if k == i:
                    i += 1
                    k = i
                    pre_sum = 0
                else:
                    pre_sum -= arr[k]
                    k += 1
            else:
                pre_sum += arr[i]

                i += 1
        if ans == float("inf"):
            return 0

        return ans


print(Solution().smallestSubWithSum(5, [1, -2, 3, 4]))
