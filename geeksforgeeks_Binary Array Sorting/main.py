class Solution:
    def binSort(self, arr):
        n = len(arr)

        i, j = 0, n - 1

        while i < j:
            if arr[i] == 0:
                i += 1
                continue

            if arr[j] == 0:
                arr[i], arr[j] = arr[j], arr[i]

            else:
                j -= 1
        print("OK1", arr)


Solution().binSort([1])
