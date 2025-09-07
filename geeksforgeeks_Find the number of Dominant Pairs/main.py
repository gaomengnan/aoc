from typing import List


class Solution:
    def dominantPairs(self, n: int, arr: List[int]) -> int:
        # n = len(arr)
        mid = n // 2
        left = arr[:mid]
        right = arr[mid:]

        left.sort()
        right.sort(reverse=True)

        # print(left, right)
        # print(mid)

        i = 0
        j = 0

        counter = 0

        # 10,8,2,1,1,2
        # 2 8 10 11
        # 2 1 1

        # endj = 0

        gap = mid

        for i in range(mid):
            if gap == 0:
                break

            for j in range(gap):
                if left[i] >= right[j] * 5:
                    counter += (mid - i) * (gap - j)
                    gap = j
                    break

        return counter


print(Solution().dominantPairs(2, [0, 0]))
