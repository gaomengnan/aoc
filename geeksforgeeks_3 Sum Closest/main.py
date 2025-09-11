class Solution:
    def closest3Sum(self, arr, target):
        arr.sort()
        n = len(arr)

        ans = float("-inf")

        for i in range(n):
            x = i + 1
            y = n - 1

            while x < y:
                thirdSum = arr[i] + arr[x] + arr[y]

                m1 = abs(thirdSum - target)
                m2 = abs(ans - target)

                # small
                if m1 < m2:
                    ans = thirdSum
                elif m1 == m2:
                    ans = max(ans, thirdSum)
                else:
                    pass

                if thirdSum < target:
                    x += 1
                elif thirdSum > target:
                    y -= 1
                else:
                    return target
        return ans


print(Solution().closest3Sum([-1, 2, 2, 4], 4))
print(Solution().closest3Sum([1, 10, 4, 5], 10))
