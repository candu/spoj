package main

import "fmt"

func main() {
  i := 0
  for {
    n, err := fmt.Scanf("%d", &i)
    if i == 42 || n != 1 || err != nil {
      break
    }
    fmt.Println(i)
  }
}
