# Sorted subsequence of size 3
# Last Updated : 23 Jul, 2025
# Given an array of n integers, find the 3 elements such that a[i] < a[j] < a[k] and i < j < k in 0(n) time. If there are multiple such triplets, then print any one of them.
class Solution:
    def find3numbers(self, arr):
        n = len(arr)
        if n < 3:
            print("No such triplet exists")
            return

        # 12, 11, 10, 5, 6, 2, 30
        # MIN = arr[0]
        min_index = 0
        mid_index = False

        for i in range(1, n):
            if arr[i] < arr[min_index]:
                min_index = i
            else:
                if mid_index is False:
                    mid_index = i
                    continue
                if arr[mid_index] > arr[i] > arr[min_index]:
                    mid_index = i

            if mid_index and arr[i] > arr[mid_index]:
                print(arr[min_index], arr[mid_index], arr[i])
                break
        print("No such triplet exists.")


a = Solution()

a.find3numbers([4, 3, 2, 1])
