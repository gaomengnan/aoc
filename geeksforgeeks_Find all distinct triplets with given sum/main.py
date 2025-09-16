# User function Template for python3
class Solution:
    def threeSum(self, arr, target):
        arr.sort()

        n = len(arr)

        ans = []

        for i in range(n - 2):
            if i > 0 and arr[i] == arr[i - 1]:
                continue
            k = i + 1
            j = n - 1

            while k < j:
                totalS = arr[i] + arr[k] + arr[j]

                if totalS == target:
                    ans.append([arr[i], arr[k], arr[j]])

                    # 跳过重复的 k
                    while k < j and arr[k] == arr[k + 1]:
                        k += 1
                    # 跳过重复的 j
                    while k < j and arr[j] == arr[j - 1]:
                        j -= 1

                    k += 1
                    j -= 1
                elif totalS < target:
                    k += 1
                else:
                    j -= 1
        return ans


print(Solution().threeSum([12, 3, 6, 1, 6, 9], 24))
