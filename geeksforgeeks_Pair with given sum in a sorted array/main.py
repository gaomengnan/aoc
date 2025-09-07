class Solution:
    def countPairs(self, arr, target):
        # Complete the function

        n = len(arr)

        i = 0
        j = n - 1

        ans = 0
        while i < j:
            toSum = arr[i] + arr[j]

            if toSum == target:
                lv = arr[i]
                rv = arr[j]

                k = i + 1
                h = j - 1

                while k < j and arr[k] == lv:
                    k += 1

                while i < h and arr[h] == rv:
                    h -= 1

                if lv == rv:
                    ans += (k - i + 1) * (k - i) // 2
                else:
                    ans += (k - i) * (j - h)
                i = k
                j = h

            elif toSum < target:
                i += 1
            else:
                j -= 1

        return ans


print(Solution().countPairs([1,1,1,1], 2))
