# User function Template for python3
#
class Solution:
    def find(self, arr, x):
        left = 0
        right = len(arr) - 1

        start = -1
        end = -1

        while left <= right:
            mid = left + (right - left) // 2

            if arr[mid] == x:
                start = mid
                end = mid
                # left
                # right
                i = mid - 1

                while i >= 0:
                    if arr[i] == x:
                        start = i
                    else:
                        break
                    i -= 1
                j = mid + 1
                while j < len(arr):
                    if arr[j] == x:
                        end = j
                    else:
                        break
                    j += 1
                break

            elif arr[mid] > x:
                right = mid - 1
            else:
                left = mid + 1

        return [start, end]


a = Solution()
print(a.find([1, 3, 5, 5, 5, 5, 7, 123, 125], 7))
