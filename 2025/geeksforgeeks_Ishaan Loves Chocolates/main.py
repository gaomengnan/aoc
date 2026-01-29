from typing import List


class Solution:
    def chocolates(self, n: int, arr: List[int]) -> int:
        i = 0
        j = n - 1
        while i <= j:
            if i == j:
                return arr[i]

            if arr[i] < arr[j]:
                j -= 1
            else:
                i += 1


print(Solution().chocolates(5, [1, 2, 3, 4, 5]))
print(Solution().chocolates(4, [5, 9, 2, 6]))
