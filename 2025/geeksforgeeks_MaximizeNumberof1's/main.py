class Solution:
    # 滑动窗口
    def maxOnes(self, arr, k):
        firstzero = False
        left = k

        start = 0
        end = 0
        res = 0

        while end < len(arr):
            if arr[end] == 0:
                if firstzero is None:
                    firstzero = end

                if left == 0:
                    res = max(res, end - start)
                    left += 1

                    while start < len(arr):
                        if arr[start] == 0:
                            start += 1
                            break
                        start += 1
                    continue

                left -= 1

            end += 1

        res = max(res, end - start)
        return res


a = Solution()
print(a.maxOnes([1, 1], 2))
