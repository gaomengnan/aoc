class Solution:
    def triplets(self, arr):
        # code here
        arr.sort()
        n = len(arr)
        ans = []
        # print(arr)
        for i in range(n - 2):
            if i > 0 and arr[i] == arr[i - 1]:
                continue

            x = i + 1
            y = n - 1

            while x < y:
                total = arr[i] + arr[x] + arr[y]
                if total == 0:
                    ans.append([arr[i], arr[x], arr[y]])

                    while x < y and arr[x] == arr[x + 1]:
                        x += 1
                    while x < y and arr[y] == arr[y + 1]:
                        y -= 1

                    x += 1
                    y -= 1
                elif total < 0:
                    x += 1

                else:
                    y -= 1

        # print(ans)

        return ans


print(Solution().triplets([-9, -1, -2]))
