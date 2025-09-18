class Solution:
    def findMax1sRow(self, mat):
        m = len(mat)
        # n = len(mat[0])
        ans = 0
        MAX = 0

        for i in range(m):
            totalS = sum(mat[i])
            if totalS > MAX:
                ans = i
                MAX = totalS

        print(ans, MAX)
        return ans


a = [[0, 0, 1, 1], [0, 1, 1, 1], [0, 0, 0, 1]]
b = [[1, 1, 1], [0, 1, 1], [1, 1, 1]]
c = [[0, 0]]

Solution().findMax1sRow(a)
Solution().findMax1sRow(b)
Solution().findMax1sRow(c)
