# User function Template for python3

# arr    : list of integers denoting the elements of the array
# target : as specified in the problem statement


class Solution:
    def threeSumClosest(self, arr, target):
        arr.sort()

        n = len(arr)

        ans = float('inf')

        for i in range(n):
            s = i + 1
            f = n - 1

            while s < f:
                toSum = arr[i] + arr[s] + arr[f]

                if toSum >= target:
                    f -= 1

                else:
                    s += 1

                m1 = abs(toSum - target)
                m2 = abs(ans - target)

                if m1 < m2:
                    ans = toSum
                elif m1 == m2:
                    ans = max(toSum, ans)
                else:
                    pass
        return ans

    #


print(Solution().threeSumClosest([5, 2, 7, 5], 13))
