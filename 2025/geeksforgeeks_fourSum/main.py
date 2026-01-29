class Solution:
    def countSum(self, arr, target):
        arr.sort()
        n = len(arr)
        counter = 0

        for i in range(n - 3):
            for j in range(i + 1, n - 2):
                T = target - arr[i] - arr[j]
                l, r = j + 1, n - 1

                while l < r:
                    s = arr[l] + arr[r]
                    if s < T:
                        l += 1
                    elif s > T:
                        r -= 1
                    else:
                        # 如果 arr[l] == arr[r]，用组合数公式
                        if arr[l] == arr[r]:
                            m = r - l + 1
                            counter += m * (m - 1) // 2
                            break
                        # 否则统计左右重复个数
                        cL, cR = 1, 1
                        while l + cL < r and arr[l + cL] == arr[l]:
                            cL += 1
                        while r - cR > l and arr[r - cR] == arr[r]:
                            cR += 1
                        counter += cL * cR
                        l += cL
                        r -= cR
        return counter


arr = [1, 1, 4, 5, 5, 7, 8, 11, 12, 12, 12, 14, 15, 16, 16, 18]
print(Solution().countSum(arr, 19))  # 输出 8
