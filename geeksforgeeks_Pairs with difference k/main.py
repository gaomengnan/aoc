# User function Template for python3
from collections import Counter


class Solution:
    def countPairs(self, arr, k):
        carr = Counter(arr)
        count = 0
        for i in arr:
            if carr[k + i] > 0:
                if k + i == i:
                    count += carr[k + i] - 1
                else:
                    count += carr[k + i]
                # carr[i] -= 1

        return count


print(Solution().countPairs([8, 16, 12, 16, 4, 0], 4))
