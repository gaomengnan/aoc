class Solution:
    def isPalinSent(self, s):
        n = len(s)
        i = 0
        j = n - 1

        while i < j:
            if not s[i].isalnum():
                i += 1
                continue  # 少了这个，否则会继续往下走
            if not s[j].isalnum():
                j -= 1
                continue  # 同理

            if s[i].lower() != s[j].lower():
                return False

            i += 1
            j -= 1

        return True


Solution().isPalinSent('i}w@(W|I')
