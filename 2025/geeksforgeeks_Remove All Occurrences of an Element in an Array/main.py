class Solution:
    def removeElement(self, arr, ele):
        n = len(arr)
        start = None
        k = 0
        for i in range(n):
            if arr[i] == ele:
                if not start:
                    start = i
            else:
                k += 1
                if start is not None:
                    arr[start], arr[i] = arr[i], arr[start]
                    start = i

        return k


print(Solution().removeElement([0, 1, 3, 0, 2, 2, 4, 2], 4))
