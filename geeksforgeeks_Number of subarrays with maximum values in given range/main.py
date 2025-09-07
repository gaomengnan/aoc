class Solution:
    def countSubarrays(self, a, n, L, R):
        last_invalid = -1
        last_valid = -1

        ans = 0

        for i in range(n):
            if a[i] > R:
                last_invalid = i
                last_valid = -1

            if L <= a[i] <= R:
                last_valid = i

            if last_valid != -1:
                ans += last_valid - last_invalid
        return ans


print(Solution().countSubarrays([3, 4, 2], 3, 2, 4))
