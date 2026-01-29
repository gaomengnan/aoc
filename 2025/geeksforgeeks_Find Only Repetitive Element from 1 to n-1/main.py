# User function Template for python3
class Solution:
    def findDuplicate(self, arr):
        n = len(arr)

        total = (n - 1) * (n) // 2

        roSum = sum(arr)

        return roSum - total


print(Solution().findDuplicate([1, 2, 2, 3, 4]))
