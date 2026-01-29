from collections import Counter, deque


class Solution:
    def removeReverse(self, S):
        freqs = Counter(S)
        dq = list(S)

        left_to_right = True
        result = []
        i = 0
        j = len(dq) - 1
        while i < j:
            if left_to_right:
                ch = dq[i]
                if freqs[ch] > 1:
                    freqs[ch] -= 1
                    left_to_right = False
                    del dq[i]
                    # i -= 1
                    j -= 1
                else:
                    i += 1
            # result.append(dq.popleft())
            else:
                ch = dq[j]
                if freqs[ch] > 1:
                    freqs[ch] -= 1
                    left_to_right = True
                    del dq[j]
                    j -= 1
                    # i -= 1
                else:
                    j -= 1
                # result.append(dq.pop())

        if left_to_right is False:
            dq.reverse()

        return "".join(dq)


# print(Solution().removeReverse("dcdbeada"))
print(Solution().removeReverse("cccea"))
# print(Solution().removeReverse("abab"))
