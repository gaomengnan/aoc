### 解题思路

1.使用queue
2. 循环遍历字串
3.找出两个/ / 之间的字

``` go
func simplifyPath(path string) string {
    // 连续多个 / 表示一个
    // .../ .... 目录
    //

	// queue := make([]string, 0)
	q := Queue{}
	// dot := 0
	runes := []byte(path)

	// dotNum := 0

	tmp := []string{}

	// /home/./foo
	// ["/home", "/foo"]

	for i, ch := range runes {
		v := string(ch)

		if v == "/" || i == len(runes)-1 {
			if len(tmp) == 0 {

				tmp = append(tmp, "/")
				continue
			}
			// 如果///
			// /./
			// /../
			// /...xx/
			if v == "/" && tmp[0] == "/" && tmp[len(tmp)-1] == "/" {
				tmp = []string{"/"}
				continue
			}

			if i == len(runes)-1 && v != "/" {
				tmp = append(tmp, v)
			}

			joined := strings.Join(tmp, "")

			if joined == "/." {
				tmp = []string{"/"}
				continue
			}
			if joined == "/.." {
				if len(q) == 0 {
					q.Append("/")
				} else {
					q.Pop()

				}
				tmp = []string{"/"}
				continue
			}
			if q.Last() == "/" {
				q.Pop()
			}
			q.Append(joined)
			tmp = []string{"/"}
			continue
		}

		tmp = append(tmp, v)

	}

	// fmt.Println(q)
	if len(q) == 0 {
		q.Append("/")
	}

	return q.String()
}

type Queue []string

func (q Queue) String() string {

	return strings.Join(q, "")
}
func (q *Queue) Append(s string) {
	// fmt.Println("appended", s)
	*q = append(*q, s)
	// fmt.Printf("%#v \n", *q)
}

func (q Queue) Last() string {
	if len(q) == 0 {
		return ""
	}
	return q[len(q)-1]
}

func (q *Queue) Pop() string {
	if len(*q) == 0 {
		return ""
	}
	val := (*q)[len(*q)-1]
	*q = (*q)[:len(*q)-1]
	return val
}


```
