class Solution:
    def kthElement(self, a, b, k):
        # code here
        ans = []
        x = 0
        y = 0
        while x < len(a) and y < len(b):
            # if x > 0 and  a[x] == a[x-1]:
            #     x +=1
            #     continue

            # if y > 0 and b[y] == b[y-1]:
            #     y +=1
            #     continue

            if a[x] < b[y]:
                ans.append(a[x])
                x += 1
            elif a[x] == b[y]:
                ans.append(a[x])
                ans.append(b[y])
                x += 1
                y += 1
            else:
                ans.append(b[y])
                y += 1

        ans.extend(a[x:])
        ans.extend(b[y:])




        return ans[k - 1]

        # 5 6 8 10


# list1 = [8, 10, 10, 11, 12, 13, 13, 13]
# list2 = [5, 6, 8, 10, 13]
# Solution().kthElement(list1, list2, 4)
