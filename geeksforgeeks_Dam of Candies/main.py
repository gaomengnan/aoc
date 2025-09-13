class Solution:
    def maxCandy(self, height, n):
        s = 0
        f = n - 1
        ans = 0

        while s < f:
            mh = min(height[s], height[f])
            ans = max(ans, mh * (f - (s + 1)))

            if height[s] < height[f]:
                s += 1
            else:
                f -= 1
        return ans


print(Solution().maxCandy([1, 3, 4], 3))
print(Solution().maxCandy([2, 1, 3, 4, 6, 5], 6))
