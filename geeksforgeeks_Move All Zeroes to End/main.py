class Solution:
    def pushZerosToEnd(self, arr):
        n = len(arr)

        start_index = False

        for i in range(0, n):
            if arr[i] == 0:
                if start_index is False:
                    start_index = i
                else:
                    pass
                    # start_index += 1
            elif arr[i] != 0 and start_index is not False:
                arr[start_index], arr[i] = arr[i], arr[start_index]
                start_index += 1


Solution().pushZerosToEnd([0, 0, 0, 1, 2])
