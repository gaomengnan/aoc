# User function Template for python3


class Solution:
    def reverseWithSpacesIntact(self, s):
        n = len(s)

        i = 0
        j = n - 1

        news = ""

        while i < n and j >= 0:
            if s[i] == " ":
                news += " "
                i += 1
                continue

            if s[j] == " ":
                j -= 1
                continue

            news += s[j]
            i += 1
            j -= 1

        return news


Solution().reverseWithSpacesIntact("Help others")
