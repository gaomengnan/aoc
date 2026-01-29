# two pointer
class Solution:
    def twoSum(self, arr, target):
        n = len(arr)

        left, right = 0, n - 1

        while True:
            if arr[left] + arr[right] > target:
                right -= 1
            elif arr[left] + arr[right] < target:
                left += 1
            else:
                return [arr[left], arr[right]]
        return [-1, -1]


a = Solution()

print(a.twoSum([2, 7, 11, 15], 9))
