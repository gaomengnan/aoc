class Solution:
    # Complete the below function
    def closestPairSum(self, arr, target):
        # Your code here
        n = len(arr)

        arr.sort()

        i = 0
        j = n - 1

        minV = float("inf")
        ans = []

        while i < j:
            totalS = arr[i] + arr[j]

            if totalS - target == 0:
                return [arr[i], arr[j]]
            else:
                m1 = abs(totalS - target)
                if m1 < minV:
                    minV = m1
                    ans = [arr[i], arr[j]]
                elif m1 == minV:
                    d1 = abs(ans[0] - ans[1])
                    d2 = abs(arr[i] - arr[j])
                    if d2 > d1:
                        ans = [arr[i], arr[j]]
                else:
                    pass

                if totalS < target:
                    i += 1
                else:
                    j -= 1
        return ans


print(Solution().closestPairSum([40, 10, 29, 28, 22, 1, 30], 54))
print(Solution().closestPairSum([10, 3, 4, 7, 1], 15))
