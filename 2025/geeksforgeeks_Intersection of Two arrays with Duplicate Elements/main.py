class Solution:
    def intersect(self, a, b):
        a.sort()
        b.sort()

        i = 0
        j = 0

        ans = []

        while i < len(a) and j < len(b):
            if i > 0 and a[i] == a[i - 1]:
                i += 1
                continue

            if j > 0 and b[j] == b[j - 1]:
                j += 1
                continue

            if a[i] < b[j]:
                i += 1
            elif a[i] > b[j]:
                j += 1
            else:
                ans.append(a[i])
                i += 1
                j += 1

        # print(ans)
        return ans


# 1 1 1 2 3
# 1 1 3 3 4

Solution().intersect([1, 2, 1, 3, 1], [3, 1, 3, 4, 1])
