class Solution:
    def removeDuplicates(self, arr):
        n = len(arr)

        res = arr[-1]

        for i in range(n - 2, -1, -1):
            if arr[i] == res:
                del arr[i]
            else:
                res = arr[i]


Solution().removeDuplicates([2, 2, 2, 4])
