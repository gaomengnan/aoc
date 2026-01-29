class Solution:
    def countTriplet(self, arr):
        arr.sort()
        n = len(arr)
        ans = 0

        for k in range(n - 1, -1, -1):
            i = 0
            j = k - 1
            while i < j:
                toSum = arr[i] + arr[j]
                if toSum == arr[k]:
                    ans += 1
                    # print(arr[i], arr[j], arr[k])
                    j -= 1
                    i += 1

                elif toSum > arr[k]:
                    j -= 1
                else:
                    i += 1

        return ans


print(Solution().countTriplet([1, 5, 3, 2]))
