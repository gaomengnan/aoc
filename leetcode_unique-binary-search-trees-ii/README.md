1️⃣ BST 的关键性质
二叉搜索树（BST）有个核心性质：

左子树的所有值 < 根节点值

右子树的所有值 > 根节点值

左右子树本身也是 BST

所以，如果我们要用 [1..n] 构建所有 BST：

每个数字 i 都可以作为根节点

左子树必须来自 [1..i-1]

右子树必须来自 [i+1..n]


递归逻辑：
如果 start > end，说明这个区间没有数字，返回 [nil]（表示空树）。

枚举区间 [start..end] 的每个数字 i 作为根节点：

递归生成所有可能的左子树：build(start, i-1)

递归生成所有可能的右子树：build(i+1, end)

组合左右子树：

左子树集合 × 右子树集合的笛卡尔积

每对组合生成一棵新树


## 如果计算数量

[[ https://leetcode.cn/problems/unique-binary-search-trees/]] 

 - 卡特兰公式
 
 Cn  = (2n)! /  n!(n+1)!
 
 ```go
// 计算阶乘
func factorial(n int) int {
	res := 1
	for i := 2; i <= n; i++ {
		res *= i
	}
	return res
} 

func catalan(n int) int {
	return factorial(2*n) / (factorial(n) * factorial(n+1))
}

 
 ```

### 递推公式

C0 =1,Cn =Cn−1 ⋅  4n−2 / n +1 (n≥1)


``` go
func catalan(n int) int {
    res := 1
    for i := 1; i <= n; i++ {
        res = res * (4*i - 2) / (i + 1)
    }
    return res
}

```
