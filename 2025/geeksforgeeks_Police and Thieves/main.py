class Solution:
    def catchThieves(self, arr, k):
        ans = 0
        i = 0
        j = 1
        while j < len(arr):
            if arr[i] == "#":
                i +=1
                continue
            if j - i > k:
                i += 1
                continue
            if arr[j] != arr[i]:
                ans += 1
                arr[j] = "#"
                i += 1
                j += 1
            else:
                j += 1

        return ans


print(Solution().catchThieves(["P", "P", "T", "P", "T"], 2))
print(Solution().catchThieves(["P", "P", "T", "T", "T"], 1))
print(Solution().catchThieves(["T", "T", "P", "P", "T", "P"], 2))
