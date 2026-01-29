class Solution:
    def countSubarrays(self, arr, k):
        n = len(arr)
        slow = 0
        fast = 0
        seq = 0
        ans = 0
        while fast < n:
            while fast < n:
                if arr[fast] % 2 != 0:
                    seq += 1
                if seq == k and fast < n - 1 and arr[fast + 1] % 2 != 0:
                    break
                if seq == k and fast == n - 1:
                    break
                fast += 1
            # print(slow, fast, seq)
            if seq == k:
                # descrease left
                lg = fast - slow + 1
                i = slow
                j = fast
                cts = 0
                if i == j:
                    seq -= 1
                while i < j:
                    while seq >= k:
                        if arr[i] % 2 == 0:
                            i += 1
                        else:
                            seq -= 1
                            cts += 1
                    if arr[j] % 2 == 0:
                        j -= 1
                    else:
                        cts += 1
                    if cts == 2:
                        break
                # [3, 5]
                a = i - slow + 1
                b = j - slow + 1
                if a == b:
                    # a⋅(n−a+1)
                    ans += a * (lg - a + 1)
                else:
                    ans += a * (lg - b + 1)
                slow = i + 1
                fast += 1
        return ans


print(Solution().countSubarrays([20, 17, 13, 1, 4, 19, 3], 1))
print(Solution().countSubarrays([2, 5, 6, 9], 2))
print(Solution().countSubarrays([2, 2, 5, 6, 9, 2, 11], 2))
