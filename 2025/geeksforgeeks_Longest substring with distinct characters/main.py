class Solution:
    def longestUniqueSubstr(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0

        slow = 0
        ans = 0
        wd = {}  # 字符 -> 上次出现的下标

        for fast in range(n):
            if s[fast] in wd and wd[s[fast]] >= slow:
                # 如果当前字符重复，更新 slow 到重复位置的下一个
                slow = wd[s[fast]] + 1

            wd[s[fast]] = fast
            ans = max(ans, fast - slow + 1)

        return ans


Solution().longestUniqueSubstr("abcdefabcbb")
