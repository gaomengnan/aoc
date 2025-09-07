# User function Template for python3
class Solution:
    def printClosest(self, arr, brr, n, m, x):
        left = 0
        right = m - 1
        if n == 0 or m == 0:
            return []

        ans = [arr[0], brr[right]]
        bestDiff = abs(x - (arr[0] + brr[right]))

        while left < n and right >= 0:
            currentSum = arr[left] + brr[right]
            currentDiff = abs(x - currentSum)

            if currentDiff < bestDiff or (
                currentDiff == bestDiff and brr[right] - arr[left] > ans[1] - ans[0]
            ):
                ans = [arr[left], brr[right]]
                bestDiff = currentDiff

            if currentSum == x:
                break
            elif currentSum > x:
                right -= 1
            else:
                left += 1

        return ans


print(Solution().printClosest([-3, -1, 2, 4], [-2, 1, 3, 5], 4, 4, 3))
