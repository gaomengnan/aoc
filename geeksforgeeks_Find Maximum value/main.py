class Solution:
    def maxValue(self, arr):
        left = 0
        right = len(arr) - 1

        ans = 0

        while left < right:
            ans = max(ans, (right - left) * (min(arr[left], arr[right])))

            if arr[left] < arr[right]:
                left += 1
            else:
                right -= 1
        return ans


print(Solution().maxValue([8, 1, 9, 4]))
