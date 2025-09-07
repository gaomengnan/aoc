class Solution:
    def countSubstr(self, s, k):
        from collections import defaultdict

        def atMost(k):
            count = defaultdict(int)
            i = 0
            res = 0
            for j in range(len(s)):
                count[s[j]] += 1
                while len(count) > k:
                    count[s[i]] -= 1
                    if count[s[i]] == 0:
                        del count[s[i]]
                    i += 1
                res += j - i + 1  # 当前窗口长度就是以 j 结尾的有效子串数量
            return res

        return atMost(k) - atMost(k - 1)


# print(Solution().countSubstr("uvgugewmed", 3))
# print(Solution().countSubstr("zatpvvsnhx", 1))
print(Solution().countSubstr("abc", 2))
# print(Solution().countSubstr("aba", 2))
# print(Solution().countSubstr("aa", 1))
