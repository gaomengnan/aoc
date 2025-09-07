# User function Template for python3


class Solution:
    ##Complete this function
    def pairInSortedRotated(self, arr, target):
        n = len(arr)

        left = 0
        right = n - 1
        point = 0

        while left < right:
            if arr[left] < arr[right]:
                point = left
                break

            mid = left + (right - left) // 2

            if mid > left and arr[mid] < arr[mid - 1]:
                point = mid
                break
            if mid < right and arr[mid] > arr[mid + 1]:
                point = mid + 1
                break

            if arr[mid] >= arr[left]:
                left = mid + 1
            else:
                right = mid - 1

        # print(point)

        lr = point

        rr = point - 1

        if rr < 0:
            rr = n - 1
        while lr != rr:
            smr = arr[lr] + arr[rr]
            if smr == target:
                return True

            if smr > target:
                rr -= 1
            else:
                lr += 1

            if rr < 0:
                rr = n - 1
            if lr > n - 1:
                lr = 0

        return False


a = Solution()
print(a.pairInSortedRotated([1, 5, 7, 9, 1, 1, 1], 16))
