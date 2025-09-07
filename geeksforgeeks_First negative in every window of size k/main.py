class Solution:
    def firstNegInt(self, arr, k):
        n = len(arr)

        left = 0
        i = 0
        found = []
        ans = []

        while i < n:
            if arr[i] < 0:
                found.append(i)
                # found = arr[i]

            if i - left + 1 == k:
                ng = 0

                if found:
                    ng = arr[found[0]]
                    # ans.append(arr[found[0]])
                else:
                    ng = 0

                ans.append(ng)

                # found = 0
                left += 1

                if found and left > found[0]:
                    found.pop(0)

            i += 1

        return ans


# 读取文件
with open("test.txt", "r", encoding="utf-8") as f:
    content = f.read()

# 按空格分割并转为整数
numbers = [int(x) for x in content.split()]

# print(len(numbers))

Solution().firstNegInt(numbers, 66)
