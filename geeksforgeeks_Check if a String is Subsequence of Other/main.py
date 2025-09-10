class Solution:
    def isSubSeq(self, s1, s2):
        i = 0

        j = 0

        while i < len(s1) and j < len(s2):
            if s1[i] == s2[j]:
                i += 1
                j +=1
            else:
                j += 1

        return i == len(s1)


print(Solution().isSubSeq("AXY", "YADXCP"))
print(Solution().isSubSeq("gksrek", "geeksforgeeks"))
