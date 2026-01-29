给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

 

示例 1：

输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：

输入：n = 1, k = 1
输出：[[1]]


### 解题

   - 使用回溯完成
   
   
``` go
func combine(n int, k int) (out [][]int) {
    // 1 2 3 4
    // 4 3 2 1 => 0 0 1 1

	var backstaCK func(path []int, startIndex int)

    
	backstaCK = func(path []int, startIndex int) {
        if len(path) == k {
            // fmt.Println("path", path)
            var tmp = make([]int, len(path))
            copy(tmp, path)
            out  = append(out, tmp)
            return
        }
		for i := startIndex; i <= n; i++ {
            path = append(path, i)
            backstaCK(path, i+1)
            path = path[:len(path)-1]
		}

	}
    backstaCK([]int{}, 1)
    return 
}

// 1 2 3

// 1 2

```
