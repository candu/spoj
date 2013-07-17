import sys

def fac(n):
  if n == 1:
    return 1
  return n * fac(n - 1)

t = int(sys.stdin.readline())
for i in range(t):
  n = int(sys.stdin.readline())
  print fac(n)
