# User function Template for python3


class Solution:
    def appleSequences(self, n, m, arr):
        slow = 0

        fast = 0

        k = m

        ans = 0

        while fast < n:
            if arr[fast] == "O":
                k -= 1

            if k < 0:
                while slow < fast:
                    if arr[slow] == "O":
                        slow += 1
                        k += 1
                        break
                    else:
                        slow += 1

                # 从 slow 开始 找到第一个 0
            if k >= 0:
                ans = max(ans, fast - slow + 1)
            fast += 1
            # slow = fo
            # k = m

        return ans


# O -> A
print(Solution().appleSequences(5, 1, "AAOOA"))
