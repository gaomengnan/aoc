### 荷兰国旗算法

算法核心思想
维护三个指针：

low：下一个 0 应该放的位置（初始指向 0）

mid：当前扫描的位置（初始指向 0）

high：下一个 2 应该放的位置（初始指向末尾）

遍历规则：

arr[mid] == 0：

把当前元素和 low 位置交换

low += 1，mid += 1

arr[mid] == 1：

说明位置正确，mid += 1

arr[mid] == 2：

把当前元素和 high 位置交换

high -= 1，但 mid 不动（因为换过来的数还没检查）

遍历直到 mid > high。

``` python

class Solution:
    def sort012(self, arr):
        low, mid, high = 0, 0, len(arr) - 1
        
        while mid <= high:
            if arr[mid] == 0:
                arr[low], arr[mid] = arr[mid], arr[low]
                low += 1
                mid += 1
            elif arr[mid] == 1:
                mid += 1
            else:  # arr[mid] == 2
                arr[mid], arr[high] = arr[high], arr[mid]
                high -= 1
        return arr


# 示例
a = Solution()
print(a.sort012([2, 1, 2, 2, 2, 1, 0]))
# 输出: [0, 1, 1, 2, 2, 2, 2]

```



