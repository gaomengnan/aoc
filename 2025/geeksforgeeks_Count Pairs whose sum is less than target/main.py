# User function Template for python3
class Solution:
    # Complete the below function
    def countPairs(self, arr, target):
        arr.sort()
        n = len(arr)
        i = 0
        j = n - 1

        ans = 0
        while i < j:
            toSum = arr[i] + arr[j]

            if toSum >= target:
                j -= 1
            else:
                ans += j - i
                i += 1

        return ans


# 1 2 2 3 4 5
# print(Solution().countPairs([7, 2, 5, 3], 8))
print(Solution().countPairs([2, 1, 8, 3, 4, 7, 6, 5], 7))
