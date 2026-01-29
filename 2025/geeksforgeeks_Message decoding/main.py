class Solution:
    def decode(self, S) -> bool:
        i = 0
        j = 0
        s = "hello"

        while i < len(S) and j < len(s):
            if S[i] == s[j]:
                i += 1
                j += 1
            else:
                i += 1

        return j == len(s)


print(Solution().decode("bbbbbxxhhelllllooudd"))
print(Solution().decode("hlelo"))
