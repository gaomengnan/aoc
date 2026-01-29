package main

import "testing"

func Test_Echo(t *testing.T) {
	echo("echo 'hello test'  'asdkjjkkjadasd''asdad'")
	echo("echo 'hello    test'  'test1'")
	echo("echo hello test  test1")
}

func Test_Cat(t *testing.T) {
	cat("cat 'main.go'")
	// cat("cat 'hello    test'  'test1'")
	// cat("cat hello test  test1")
}
