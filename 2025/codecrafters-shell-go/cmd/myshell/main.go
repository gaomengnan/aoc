package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"os/exec"
	"strings"
)

// Ensures gofmt doesn't remove the "fmt" import in stage 1 (feel free to remove this!)
var _ = fmt.Fprint

type handler func(cmd string) error

var cmds = map[string]handler{
	"echo": echo,
	"type": types,
	"pwd":  pwd,
	"cd":   cd,
	"cat":  cat,
}

func parseSubArgs(str string) []string {
	var quota rune

	var bf bytes.Buffer
	var result []string

	// var escape int

	// 类似这个需要输出出来
	// prevEscape := false

	escapes := make(map[int]struct{})

	var check func(data bytes.Buffer, i int) ([]byte, bool)
	check = func(data bytes.Buffer, i int) ([]byte, bool) {

		if data.Len() > 0 {
			_buf := data.Bytes()
			// 如果上一个为\
			if _buf[data.Len()-1] == '\\' {

				_, ok := escapes[data.Len()-1]

				if ok {
					return data.Bytes(), false
				}

				_buf = append(_buf[:data.Len()-1], _buf[data.Len()-1+1:]...)
				// data.Reset()
				// data.Write(_buf)
				return _buf, true
			}
		}
		return data.Bytes(), false
	}

	for _i, item := range str {
		// 如果当前为\ 那么后面一个是否为 \
		// 并且前一个不是转义
		// \' \"
		// \\1asd

		// hasEscape := false

		// if escape == 0 && item == '\\' {
		//   escape ++
		//   continue
		// }

		if quota == 0 && (item == '\'' || item == '"') {

			newB, ok := check(bf, _i)

			if ok {
				bf.Reset()
				bf.Write(newB)
				goto A
			}

			// if bf.Len() >= _i-1 && _i-1 >= 0 {
			//   _buf := bf.Bytes()
			//   // 如果上一个为\
			//   if _buf[_i-1] == '\\' {
			//     _buf = append(_buf[:_i-1], _buf[_i-1+1:]...)
			//     bf.Reset()
			//     bf.Write(_buf)
			//     goto A
			//   }
			// }

			// if hasEscape  {
			// 	goto A
			// }

			quota = item
			// bf.Reset()
			continue
		}

	A:
		if quota != 0 && item == quota {
			newB, ok := check(bf, _i)
			if ok {
				bf.Reset()
				bf.Write(newB)
				goto B
			}
			// if hasEscape {
			//   goto B
			// }
			// 如果下一个为空格
			if _i+1 < len(str) {
				if str[_i+1] == ' ' {
					quota = 0
					result = append(result, bf.String())
					bf.Reset()
					continue
				}
				continue
			}

			continue
		}

	B:
		if quota != 0 {
			// if item == '\\' && !hasEscape && quota =='"' {
			//   item = 0
			// }
			// fmt.Printf("%d --- %v \n", _i,  string(item))
			newB, ok := check(bf, _i)

			if ok && (item == '\\') {
				bf.Reset()
				bf.Write(newB)
			}

			bf.WriteRune(item)

			if item == '\\' && ok {
				escapes[bf.Len()-1] = struct{}{}
			}
			continue
		}

		if quota == 0 {
			nv, ok := check(bf, _i)

			if item == ' ' && !ok {
				if bf.Len() > 0 {
					result = append(result, bf.String())
				}
				bf.Reset()
				continue
			} else {
				// fmt.Printf("%d --- %#v \n", _i,  item)
				// if item == '\\' && !hasEscape {
				// 	item = 0
				// }
				if ok {
					bf.Reset()
					bf.Write(nv)
				}
				bf.WriteRune(item)
				continue
			}
		}
	}
	if bf.Len() > 0 {
		result = append(result, bf.String())
	}

	return result
}

func cd(cmd string) error {
	sp := strings.SplitN(cmd, " ", 2)
	if sp[1] == "~" {
		sp[1], _ = os.UserHomeDir()
	}

	if err := os.Chdir(sp[1]); err != nil {
		fmt.Printf("cd: %s: No such file or directory \n", sp[1])
	}
	return nil
}

func echo(cmd string) error {
	sp := strings.SplitN(cmd, " ", 2)
	// fields := strings.Split(sp[1], "'")

	result := parseSubArgs(sp[1])
	// fmt.Printf("%#v", result)

	for i, f := range result {
		fmt.Print(f)

		if i < len(result)-1 {
			fmt.Print(" ")
		}
	}

	fmt.Print("\n")

	return nil
}

func cat(cmd string) error {
	sp := strings.SplitN(cmd, " ", 2)
	// fields := strings.Split(sp[1], "'")

	result := parseSubArgs(sp[1])
	// fmt.Printf("%#v", result)

	for _, f := range result {
		content, err := os.ReadFile(f)
		if err != nil {
			fmt.Println(err)
			return nil
		}
		fmt.Print(string(content))
		// if i < len(result) - 1 {
		//   fmt.Print(" ")
		// }
	}

	// fmt.Print("\n")

	return nil
}

func pwd(cmd string) error {
	path, err := os.Getwd()
	if err != nil {
		return nil
	}
	fmt.Println(path)
	return nil
}

func types(cmd string) error {
	sp := strings.SplitN(cmd, " ", 2)
	ecmd := exec.Command("sh", "-c", cmd)
	// ecmd.Env = append(ecmd.Env, os.Getenv("PATH"))
	_rest, err := ecmd.Output()

	typeCmd := strings.Trim(sp[1], "\r\n")

	if err != nil {
		pathseq := os.Getenv("PATH")
		seqs := strings.Split(pathseq, ":")
		for _, item := range seqs {
			enties, err := os.ReadDir(item)
			if err != nil {
				continue
			}

			for _, entiry := range enties {
				if entiry.Name() == typeCmd {
					_rest = []byte(fmt.Sprintf("%s is %s/%s \n", typeCmd, item, typeCmd))
					goto ret
				}
			}
		}
		fmt.Println(typeCmd + ": not found")
		return err
	}
ret:
	fmt.Print(string(_rest))
	return nil
}

func main() {
	// Uncomment this block to pass the first stage
	for {
		fmt.Fprint(os.Stdout, "$ ")

		// Wait for user input
		in, err := bufio.NewReader(os.Stdin).ReadString('\n')
		if err != nil {
			fmt.Fprintln(os.Stderr, "Error reading input:", err)
			os.Exit(1)
		}

		clear_in := strings.TrimRight(in, "\n")

		if clear_in == "exit 0" {
			os.Exit(0)
		}

		cmdsp := strings.Split(clear_in, " ")

		if len(cmdsp) == 0 {
			os.Exit(-1)
		}

		handler := cmds[cmdsp[0]]

		if handler != nil {
			handler(clear_in)
		} else {
			_cmd := exec.Command(cmdsp[0], cmdsp[1:]...)
			_cmd.Stderr = os.Stderr
			_cmd.Stdout = os.Stdout
			err := _cmd.Run()
			if err != nil {
				fmt.Println(in[:len(in)-1] + ": command not found")
			}
		}

	}
}
