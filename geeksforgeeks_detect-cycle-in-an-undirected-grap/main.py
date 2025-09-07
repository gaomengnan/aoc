class Solution:
    def isCycle(self, V, edges):
        # 建图
        graph = [[] for _ in range(V)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = [False] * V

        # DFS 检查是否有环
        def dfs(node, parent):
            visited[node] = True
            for nei in graph[node]:
                if not visited[nei]:
                    if dfs(nei, node):
                        return True
                elif nei != parent:  # 遇到已访问的点且不是父节点 => 有环
                    return True
            return False

        # 可能是非连通图，所以每个连通分量都要检查
        for i in range(V):
            if not visited[i]:
                if dfs(i, -1):
                    return True
        return False


# 测试
a = Solution()
print(a.isCycle(4, [[0, 1], [0, 2], [1, 2], [2, 3]]))  # True
print(a.isCycle(3, [[0, 1], [1, 2]]))  # False
