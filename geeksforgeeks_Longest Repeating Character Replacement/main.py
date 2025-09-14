from collections import Counter


class Solution:
    def characterReplacement(self, s, k):
        left = 0
        max_freq = 0  # 记录窗口内字符出现的最大频率
        freq = Counter()  # 记录每个字符的频率
        ans = 0

        for right in range(len(s)):
            # 计算当前字符的频率
            freq[s[right]] += 1

            # 更新窗口内字符的最大频率
            max_freq = max(max_freq, freq[s[right]])

            # 如果当前窗口的大小减去最大频率大于 k，说明需要缩小窗口
            if (right - left + 1) - max_freq > k:
                # 缩小窗口，左指针右移
                freq[s[left]] -= 1
                left += 1

            # 计算当前窗口的大小
            ans = max(ans, right - left + 1)

        return ans


def test():
    sol = Solution()

    # assert sol.characterReplacement("ABCBABCD", 2) == 4  # "BBBB" or "ABCB"
    # return
    # Basic test cases
    assert (
        sol.characterReplacement("ABAB", 2) == 4
    )  # Replace 'A's with 'B's to get "BBBB"
    assert sol.characterReplacement("AABABBA", 1) == 4  # Replace middle 'B' with 'A'
    assert sol.characterReplacement("BAAAB", 2) == 5  # Replace 'B's with 'A's
    assert (
        sol.characterReplacement("ABCDE", 1) == 2
    )  # Any adjacent pair can be made same

    # Edge cases
    assert sol.characterReplacement("A", 1) == 1  # Single character
    assert sol.characterReplacement("", 2) == 0  # Empty string
    assert sol.characterReplacement("AAA", 0) == 3  # Already all same characters

    # K = 0 cases
    assert sol.characterReplacement("ABCD", 0) == 1  # No replacements allowed
    assert (
        sol.characterReplacement("AABB", 0) == 2
    )  # No replacements needed for length 2

    # Large K cases
    assert sol.characterReplacement("ABCD", 4) == 4  # K larger than string length
    assert sol.characterReplacement("ABCDE", 10) == 5  # K much larger than needed

    # Multiple possible solutions
    assert (
        sol.characterReplacement("AAABBC", 2) == 5
    )  # Can make either all A's or all B's
    assert sol.characterReplacement("ABABA", 2) == 5  # Can make all A's or all B's

    # Repeated patterns
    assert sol.characterReplacement("AABABAB", 3) == 7  # Convert all to A's
    assert sol.characterReplacement("AABAABAA", 1) == 5  # "AABAA" is longest possible

    # Complex cases
    assert sol.characterReplacement("ABCBABCD", 2) == 5  # "BBBBB" or "ABCB"
    assert sol.characterReplacement("AABABAAB", 2) == 7  # Need to find optimal window
    assert sol.characterReplacement("ABCBABBA", 2) == 6  # Multiple possible windows

    # Test cases with different characters
    assert sol.characterReplacement("XYZXY", 2) == 4  # Can make "XXXX" or "YYYY"
    assert sol.characterReplacement("PQRSTU", 3) == 4  # Any 4 chars can be made same

    print("All test cases passed!")


if __name__ == "__main__":
    test()
