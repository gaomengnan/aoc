class Solution:
    def findDuplicate1(self, arr):
        for i in range(0, len(arr)):
            for j in range(i + 1, len(arr)):
                if arr[i] == arr[j] and i != j:
                    return arr[i]

        return -1

    ## 排序
    def findDuplicate2(self, arr):
        arr = sorted(arr)

        for i in range(1, len(arr)):
            if arr[i] == arr[i - 1]:
                return arr[i]

        return -1

    ## hashMap
    def findDuplicate3(self, arr):
        hm = {}

        for i in arr:
            if hm.get(i):
                return i
            hm[i] = True
        return -1

    def findDuplicate4(self, arr):
        n = len(arr)

        totalSum = sum(arr)
        duplicate = totalSum - ((n - 1) * n // 2)

        return duplicate

    def findDuplicate(self, arr):
        n = len(arr)
        res = 0

        for i in range(0, n - 1):
            res = res ^ (i + 1) ^ arr[i]

        res ^= arr[n - 1]

        return res


a = Solution()

print(a.findDuplicate([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 7]))  # Output: -1
