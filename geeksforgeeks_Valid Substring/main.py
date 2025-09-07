class Solution:
    def maxLen(ob, s):
        n = len(s)

        wd = [0] * n

        fast = 0

        lPair = []

        ans = 0

        while fast < n:
            if s[fast] == "(":
                lPair.append(fast)
            else:
                if lPair:
                    res = lPair.pop()
                    wd[res] = 1
                    wd[fast] = 1
            fast += 1

        # print(wd)

        s = None

        for i in range(len(wd)):
            if s is None and wd[i] == 1:
                s = i

            if wd[i] == 0:
                s = None

            if s is not None:
                ans = max(ans, i - s + 1)

        return ans


print(Solution().maxLen("(()("))
print(Solution().maxLen("()(())("))
print(Solution().maxLen("(()())"))
print(Solution().maxLen(")()())"))  # 输出: 4   -> "()()"
print(Solution().maxLen("()(()"))  # 输出: 2   -> "()"


print(Solution().maxLen("(()"))  # 输出: 2   -> "()"
print(Solution().maxLen(""))  # 输出: 0   -> 空字符串
print(Solution().maxLen("()(())"))  # 输出: 6   -> "()(())"
print(Solution().maxLen("())((())"))  # 输出: 4   -> "(())"
print(Solution().maxLen("(()())"))  # 输出: 6   -> "(()())"
print(Solution().maxLen("((((("))  # 输出: 0   -> 没有有效子串
print(Solution().maxLen(")()())()()("))  # 输出: 4   -> "()()"
