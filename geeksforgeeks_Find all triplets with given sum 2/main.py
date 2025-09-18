class Solution:
    def findTriplets(self, arr, k):
        arr.sort()

        n = len(arr)
        ans = []

        for i in range(n):
            if i > 0 and arr[i] == arr[i - 1]:
                continue
            x = i + 1
            z = n - 1

            while x < z:
                tot = arr[i] + arr[x] + arr[z]

                if tot == k:
                    ans.append([arr[i], arr[x], arr[z]])

                    while x < z and arr[x] == arr[x + 1]:
                        x += 1

                    while x < z and arr[z] == arr[z - 1]:
                        z -= 1

                    x += 1
                    z -= 1

                elif tot < k:
                    x += 1
                else:
                    z -= 1

        return ans


print(Solution().findTriplets([0, -1, 2, -3, 1], -2))
