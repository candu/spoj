package main

import (
  "bufio"
  "fmt"
  "strconv"
  "strings"
  "os"
)

func ReadLine(reader *bufio.Reader) (string, error) {
  s, err := reader.ReadString('\n')
  if err != nil {
    return "", err
  }
  s = strings.TrimRight(s, "\n")
  return s, nil
}

func ParseRPN(s string) string {
  i := 0
  rpn := make([]byte, 0, len(s))
  var ParseRPNHelper func()
  ParseRPNHelper = func() {
    if s[i] != '(' && s[i] != ')' {
      rpn = append(rpn, s[i])
      i++
      return
    }
    i++
    ParseRPNHelper()
    op := s[i]
    i++
    ParseRPNHelper()
    rpn = append(rpn, op)
    i++
  }
  ParseRPNHelper()
  return string(rpn)
}

func main() {
  stdin := bufio.NewReader(os.Stdin)
  s, _ := ReadLine(stdin)
  n, _ := strconv.Atoi(s)
  for i := 0; i < n; i++ {
    s, _ := ReadLine(stdin)
    rpn := ParseRPN(s)
    fmt.Println(rpn)
  }
}
