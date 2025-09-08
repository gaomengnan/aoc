class Solution:
    def countTriplets(self, arr, target):
        # 不需要排序
        n = len(arr)
        ans = 0

        for i in range(n):
            x = i + 1
            y = n - 1

            while x < y:
                toSum = arr[i] + arr[x] + arr[y]

                k = x
                z = y

                if toSum == target:
                    # s1 = arr[x]
                    while k < y:
                        if arr[x] == arr[k]:
                            k += 1
                        else:
                            break

                    while z > x:
                        if arr[z] == arr[y]:
                            z -= 1
                        else:
                            break

                    if arr[x] == arr[y]:
                        ans += (k-x+1) * (k-x) // 2
                    else:
                        ans += (k - x) * (y - z)

                    x = k
                    y = z

                elif toSum < target:
                    x += 1
                else:
                    y -= 1
        return ans


print(Solution().countTriplets([0, 0, 0, 0, 0, 0], 0))
