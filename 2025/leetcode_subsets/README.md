```go
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
```

### 解题
- 使用dfs 
  1. 递归
  
  ```go
 func subsets(nums []int) (out [][]int) {
 	var dfs func(path []int, startIndex int)

 	dfs = func(path []int, startIndex int) {
 		if len(path) > 1 {
 			tmp := make([]int, len(path))
 			copy(tmp, path)
 			out = append(out, tmp)
 		}

 		for i := startIndex; i < len(nums); i++ {
 			path = append(path, nums[i])
 			dfs(path, i+1)
 			path = path[:len(path)-1]

 		}
 	}

 	out = append(out, []int{})
 	for i := range nums {
 		out = append(out, []int{nums[i]})
 	}
 	dfs([]int{}, 0)
 	return
 }
  ```

  2. stck 方式
  
  ```go
func subsets(nums []int) (out [][]int) {
	type Frame struct {
		path       []int // 当前子集
		startIndex int   // 下一次从哪里开始
	}

	stack := []Frame{{[]int{}, 0}}

	for len(stack) > 0 {
		// 弹出栈顶
		n := len(stack) - 1
		curr := stack[n]
		stack = stack[:n]

		// 收集当前路径
		tmp := make([]int, len(curr.path))
		copy(tmp, curr.path)
		out = append(out, tmp)

		// 从当前 startIndex 开始，继续向后尝试
		for i := len(nums) - 1; i >= curr.startIndex; i-- {
			// 构造新的 path，加入下一个数字 nums[i]
			newPath := append([]int{}, curr.path...)  // 拷贝一份
			newPath = append(newPath, nums[i])
			// 把下一步压入栈中
			stack = append(stack, Frame{newPath, i + 1})
		}
	}
	return
}
```
  
