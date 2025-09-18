# User function Template for python3
class Solution:
    # Complete the below function
    def countPairs(self, arr, target):
        n = len(arr)
        i = 0
        j = n - 1
        ans = 0
        while i < j:
            totalS = arr[i] + arr[j]
            if totalS < target:
                ans += j - i
                i += 1
            else:
                j -= 1

        # print(ans)
        return ans


print(Solution().countPairs([2, 3, 5, 7], 8))
print(Solution().countPairs([1, 2, 3, 4, 5, 6, 7, 8], 7))
