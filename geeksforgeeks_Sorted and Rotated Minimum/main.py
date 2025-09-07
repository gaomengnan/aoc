# User function Template for python3
class Solution:
    def findMin(self, arr):
        left, right = 0, len(arr) - 1

        while left < right:
            if arr[left] < arr[right]:
                return arr[left]

            mid = left + (right - left) // 2

            # 找到旋转点
            if mid < right and arr[mid] > arr[mid + 1]:
                return arr[mid + 1]
            if mid > left and arr[mid] < arr[mid - 1]:
                return arr[mid]

            if arr[mid] >= arr[left]:
                left = mid + 1
            else:
                right = mid - 1

        return arr[left]


a = Solution()




a = Solution()

a.findMin([2, 1])


