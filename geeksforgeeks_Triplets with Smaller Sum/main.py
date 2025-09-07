class Solution:
    def countTriplets(self, n, sum, arr):
        ans = 0
        arr.sort()
        for i in range(n):
            x = i + 1
            y = n - 1

            while x < y:
                toSum = arr[i] + arr[x] + arr[y]

                if toSum >= sum:
                    y -= 1
                else:
                    ans += y - x
                    x += 1
        return ans


# -2, 0, 1, 3
# 1 3 4 5 7 12
print(Solution().countTriplets(5, 12, [5, 1, 3, 4, 7]))
