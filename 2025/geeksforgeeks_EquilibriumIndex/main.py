class Solution:
    def findEquilibrium(self, arr):
        total = sum(arr)

        pre_sum = 0
        for i in range(0, len(arr)):
            if total - pre_sum - arr[i] == pre_sum:
                return i
            pre_sum += arr[i]
        return -1


a = Solution()
print(a.findEquilibrium([1, 2, 0, 3]))
print(a.findEquilibrium([1, 1, 1, 1]))
print(a.findEquilibrium([-7, 1, 5, 2, -4, 3, 0]))
