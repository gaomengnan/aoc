class Solution:
    def celebrity(self, mat):
        n = len(mat)

        i = 0
        j = n - 1

        ans = -1
        while i < j:
            if mat[i][j] == 1 and i != j:
                # 说明 i 认识
                # 自己认识自己
                i += 1
            else:
                j -= 1

        ans = i

        # print(ans)
        for i in range(n):
            if i != ans:
                if mat[ans][i] == 1 or mat[i][ans] == 0:
                    return -1

        return ans

        # print(cs)
        # print(kcs)


# 测试数据
mat1 = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]  # 期望结果：1

mat2 = [[1, 0, 1], [0, 1, 0], [0, 1, 1]]  # 期望结果：-1（没有名人）

mat3 = [[1, 0, 0], [1, 1, 0], [1, 1, 1]]  # 期望结果：0

mat4 = [[1, 1, 1], [0, 1, 0], [0, 1, 1]]  # 期望结果：1

print(Solution().celebrity(mat1))
print(Solution().celebrity(mat2))
print(Solution().celebrity(mat3))
print(Solution().celebrity(mat4))
