class Solution:
    def intersectSize(self, a, b):
        """
        返回两个具有不同元素的数组交集中的元素数量。
        
        参数:
            a (list): 第一个包含不同元素的未排序数组
            b (list): 第二个包含不同元素的未排序数组
            
        返回:
            int: 两个数组之间公共元素的数量
            
        示例:
            >>> solution = Solution()
            >>> solution.intersectSize([1, 2, 3, 4, 5, 6], [3, 4, 5, 6, 7])
            4
            >>> solution.intersectSize([10, 20, 30, 40, 50], [15, 20, 25, 30, 35])
            2
        """
        # 对两个数组进行排序以启用双指针技术
        a.sort()
        b.sort()

        # 初始化指针和计数器
        i = 0
        j = 0
        counter = 0

        # 使用双指针遍历两个数组
        while i < len(a) and j < len(b):
            if a[i] < b[j]:
                # 数组a中的元素较小，将指针i向前移动
                i += 1
            elif a[i] == b[j]:
                # 找到公共元素，增加计数器并移动两个指针
                counter += 1
                i += 1
                j += 1
            else:
                # 数组b中的元素较小，将指针j向前移动
                j += 1

        return counter


# 测试实现
if __name__ == "__main__":
    solution = Solution()
    
    # 测试用例 1
    a1 = [1, 2, 3, 4, 5, 6]
    b1 = [3, 4, 5, 6, 7]
    result1 = solution.intersectSize(a1, b1)
    print(f"测试 1: {result1}")  # 预期: 4
    
    # 测试用例 2
    a2 = [10, 20, 30, 40, 50]
    b2 = [15, 20, 25, 30, 35]
    result2 = solution.intersectSize(a2, b2)
    print(f"测试 2: {result2}")  # 预期: 2
    
    # 测试用例 3 - 无公共元素
    a3 = [1, 3, 5]
    b3 = [2, 4, 6]
    result3 = solution.intersectSize(a3, b3)
    print(f"测试 3: {result3}")  # 预期: 0
    
    # 测试用例 4 - 所有元素都公共
    a4 = [1, 2, 3]
    b4 = [1, 2, 3]
    result4 = solution.intersectSize(a4, b4)
    print(f"测试 4: {result4}")  # 预期: 3
