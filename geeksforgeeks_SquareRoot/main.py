class Solution:
    def floorSqrt(self, n):
        if n == 1:
            return 1

        if n == 0:
            return 0

        left = 1
        right = n // 2

        res = None

        while left <= right:
            mid = left + (right - left) // 2

            sq = mid * mid

            if not res:
                res = mid

            elif sq < n and abs(n - sq) < abs(n - (res * res)):
                res = mid

            if sq == n:
                return mid

            if sq > n:
                right = mid - 1
            if sq < n:
                left = mid + 1
        return res


a = Solution()
print(a.floorSqrt(10))
