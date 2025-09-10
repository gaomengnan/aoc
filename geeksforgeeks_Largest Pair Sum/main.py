from typing import List


class Solution:
    def pairsum(self, arr: List[int]) -> int:
        arr.sort()

        return arr[-1] + arr[-2]


print(Solution().pairsum([1, 2, 3, 3, 4, 5]))
