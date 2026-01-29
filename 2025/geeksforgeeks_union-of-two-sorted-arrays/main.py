class Solution:
    def findUnion(self, a, b):
        # code here
        i = 0
        j = 0
        res = []
        while i < len(a) and j < len(b):
            v1 = a[i]
            v2 = b[j]
            if i > 0 and a[i] == a[i - 1]:
                i += 1
                continue
            if j > 0 and b[j] == b[j - 1]:
                j += 1
                continue

            # 1 2 3 4 5
            # 3 6 7

            if v1 < v2:
                res.append(v1)
                i += 1
            elif v1 == v2:
                res.append(v1)
                i += 1
                j += 1
            else:
                res.append(v2)
                j += 1

        for x in range(i, len(a)):
            if x > 0 and a[x] == a[x - 1]:
                continue
            res.append(a[x])

        for y in range(j, len(b)):
            if y > 0 and b[y] == b[y - 1]:
                continue
            res.append(b[y])

        return res


# a = Solution()
# a.findUnion([2, 2, 3, 4, 5], [1, 1, 2, 3, 4])

# 帮我创建20个sample 其他不要多说


samples = [
    (
        [
            4,
            6,
            6,
            9,
            10,
            11,
            11,
            11,
        ],
        [1, 1, 1, 3, 3],
    ),
    ([], []),
    ([1, 2, 3, 4], [5, 6, 7, 8]),
    ([1, 3, 5], [1, 3, 5, 7, 9]),
    ([2, 2, 4, 4, 6], [4, 4, 8, 10]),
    ([100, 200, 300], [150, 200, 250, 350]),
]

sol = Solution()
for a, b in samples:
    print(sol.findUnion(a, b))
