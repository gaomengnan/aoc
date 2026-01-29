class Solution:
    def search(self, arr, key):
        n = len(arr)
        left = 0
        right = n - 1
        while left <= right:
            mid = left + (right - left) // 2

            if arr[mid] == key:
                return mid

            if arr[left] < arr[right]:
                if arr[mid] < key:
                    left = mid + 1
                else:
                    right = mid - 1
                continue

            if arr[mid] >= arr[left]:
                if arr[left] <= key < arr[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if arr[mid] < key <= arr[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1


a = Solution()
print(a.search([5, 6, 7, 8, 9, 10, 1, 2, 3], 3))  # Example usage
print(a.search([5, 6, 7, 8, 9, 10, 1, 2, 3], 11))  # Example usage
print(a.search([3, 5, 1, 2], 6))
print(a.search([33, 42, 72, 99], 42))
