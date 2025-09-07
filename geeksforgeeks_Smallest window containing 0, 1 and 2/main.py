# User function Template for python3


class Solution:
    def smallestSubstring(self, S):
        n = len(S)
        i = 0
        wd = {}
        ans = float("inf")

        for j in range(n):
            wd[S[j]] = wd.get(S[j], 0) + 1

            # 窗口包含三个字符时，尝试缩小左边界
            while len(wd) == 3:
                ans = min(ans, j - i + 1)

                wd[S[i]] -= 1
                if wd[S[i]] == 0:
                    del wd[S[i]]
                i += 1

        return ans if ans != float("inf") else -1


# print(Solution().smallestSubstring("1210"))
# print(Solution().smallestSubstring("000111222"))
print(
    Solution().smallestSubstring(
        "11020122212022012002002011211111020020222011012121121001222221222200012220101202120102102212102222212100112002001002011222221210110102002211202121021102211120202111221221101001121201101121001102222202012210112201101020000101011200000102201010101011120102020012211111100211220002200011021000101001111022211002212110221220011122021110220121222110010012001000222211212011110101121211020210"
    )
)
