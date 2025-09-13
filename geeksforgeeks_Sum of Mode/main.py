from collections import defaultdict


class Solution:
    def sumOfModes(self, arr, k):
        n = len(arr)
        slow = 0
        fast = 0

        cnt = defaultdict(int)  # 数字 -> 出现次数

        freq_map = defaultdict(set)  # 次数 -> 哪些数字

        max_freq = 0

        ans = 0

        while fast < n:
            num = arr[fast]
            old = cnt[num]

            if old > 0:
                freq_map[old].remove(num)
                if not freq_map[old]:
                    del freq_map[old]

            cnt[num] += 1

            freq_map[cnt[num]].add(num)

            max_freq = max(max_freq, cnt[num])

            if fast - slow + 1 > k:
                num = arr[slow]
                old = cnt[num]
                freq_map[old].remove(num)

                if not freq_map[old]:
                    del freq_map[old]

                cnt[num] -= 1

                if cnt[num] > 0:
                    freq_map[cnt[num]].add(num)
                if old == max_freq and old not in freq_map:
                    max_freq -= 1

                slow += 1

            # 等于 K
            # 计算这个
            if fast - slow + 1 == k:
                ans += min(freq_map[max_freq])

            fast += 1
        return ans


print(Solution().sumOfModes([1, 2, 1, 3, 5], 2))
