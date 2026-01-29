"""
class Node:
    def _init_(self, x):
        self.data = x
        self.next = None
"""

import sys, os

sys.path.append(os.path.dirname(os.path.dirname(__file__)))

from leetcode_utils import util
from itertools import chain

import heapq


# 先合并 node ==> list
# 合并 list ==> one


class Solution:
    def merge_k_sorted(self, arrs):
        heap = []
        result = []

        # 初始化，把每个数组的第一个元素放进堆
        for i, sub in enumerate(arrs):
            if sub:  # 非空
                heapq.heappush(heap, (sub[0], i, 0))  # (值, 属于哪个数组, 在数组的下标)

        while heap:
            val, i, j = heapq.heappop(heap)
            result.append(val)
            # 如果该数组还有下一个元素，继续放入堆
            if j + 1 < len(arrs[i]):
                heapq.heappush(heap, (arrs[i][j + 1], i, j + 1))

        return result

    def mergeKLists(self, arr):
        def mergeNode(first, second):
            cur1 = first
            cur2 = second

            merged = []

            while cur1 and cur2:
                if cur1.data < cur2.data:
                    merged.append(cur1.data)
                    cur1 = cur1.next
                elif cur1.data == cur2.data:
                    merged.append(cur1.data)
                    cur1 = cur1.next
                    merged.append(cur2.data)
                    cur2 = cur2.next
                else:
                    merged.append(cur2.data)
                    cur2 = cur2.next

            while cur1:
                merged.append(cur1.data)
                cur1 = cur1.next

            while cur2:
                merged.append(cur2.data)
                cur2 = cur2.next

            return merged

        sp = [arr[i : i + 2] for i in range(0, len(arr), 2)]

        mergeds = []

        for j in sp:
            if len(j) == 2:
                mergeds.append(mergeNode(j[0], j[1]))
            else:
                mergeds.append(mergeNode(j[0], None))
        res = self.merge_k_sorted(mergeds)

        print(res)

        # merged = list(chain.from_iterable(mergeds))

        # print(merged)
        return util.create_linked_list(res)


Solution().mergeKLists(
    [
        util.create_linked_list(
            [
                1,
                3,
                7,
            ],
        ),
        util.create_linked_list(
            [
                2,
                4,
                8,
            ],
        ),
        util.create_linked_list([9]),
    ]
)
