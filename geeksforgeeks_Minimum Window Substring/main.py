class Solution:
    def minWindow(self, s1: str, s2: str) -> str:
        n, m = len(s1), len(s2)
        ans = ""
        min_len = float("inf")

        i = 0
        while i < n:
            # step1: 找到匹配起点
            if s1[i] == s2[0]:
                j, k = i, 0
                while j < n and k < m:  # 前向匹配
                    if s1[j] == s2[k]:
                        k += 1
                    j += 1

                if k == m:  # s2 匹配完了
                    end = j - 1
                    k -= 1
                    # step2: 从右往左收缩，找到最小 start
                    while end >= i:
                        if s1[end] == s2[k]:
                            k -= 1
                            if k < 0:
                                break
                        end -= 1
                    start = end
                    if j - start < min_len:
                        min_len = j - start
                        ans = s1[start:j]
                    i = start  # 跳到更优的起点
            i += 1

        return ans


# print(Solution().minWindow("ADOBECODEBANC", "ABC"))
# print(Solution().minWindow("geeksforgeeks", "eksrg"))
# print(Solution().minWindow("adeacbabdcdecabc", "abc"))
# print(Solution().minWindow("ab", "d"))
# print(Solution().minWindow("defdfegdegeegdddeg", "deeg"))
# print(Solution().minWindow("stustsustutssu", "ssuu"))
# print(Solution().minWindow("jkjjjkjkjkjjjkkjjkjkkkjkkkkj", "jkjkj"))
print(Solution().minWindow("oppopppopooopooopooo", "ppooooo"))
