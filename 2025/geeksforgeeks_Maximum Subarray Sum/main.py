class Solution:
    def maxSubarraySum(self, arr):
        """
        This function finds the maximum subarray sum using Kadane's algorithm.
        :param arr: List[int] - List of integers
        :return: int - Maximum subarray sum
        """
        max_ending_sum = arr[0]
        max_so_far = arr[0]

        for i in range(1, len(arr)):
            max_ending_sum = max(arr[i], max_ending_sum + arr[i])
            max_so_far = max(max_so_far, max_ending_sum)

        return max_so_far


a = Solution()
print(a.maxSubarraySum([2, 3, -8, 7, -1, 2, 3]))  # output 11
print(a.maxSubarraySum([-2, -4]))  # output 11
print(a.maxSubarraySum([5, 4, 1, 7, 8]))  # output 11
