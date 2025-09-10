class Solution:
    def minimumCoins(self, arr, k):
        arr.sort()
        n = len(arr)
        maxVal = arr[-1]

        i = 0
        j = n - 1

        while i < j:
            print(i, j)
            diffV = arr[j] - arr[i]

            if diffV <= k:
                return 0
            i += 1
            j -= 1
        return -1

    # 1 1 1 2 5 5


print(Solution().minimumCoins([1, 5, 1, 2, 5, 1], 3))
