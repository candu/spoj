#include "math.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"
#include "time.h"

void sieve(int lo, int hi) {
  int i, j, d;
  d = hi - lo + 1;
  bool flag[d];
  for (i = 0; i < d; i++) {
    flag[i] = true;
  }
  for (i = (lo % 2 != 0); i < d; i += 2) {
    flag[i] = false;
  }
  int s = sqrt(hi);
  for (i = 3; i <= s; i += 2) {
    if (i > lo && !flag[i - lo]) {
      continue;
    }
    j = lo / i * i;
    if (j < lo) {
      j += i;
    }
    if (j == i) {
      j += i;
    }
    j -= lo;
    for (; j < d; j += i) {
      flag[j] = false;
    }
  }
  if (lo <= 1) {
    flag[1 - lo] = false;
  }
  if (lo <= 2) {
    flag[2 - lo] = true;
  }
  for (i = 0; i < d; i++) {
    if (flag[i]) {
      printf("%d\n", lo + i);
    }
  }
  printf("\n");
}

int main() {
  int t, i, m, n;
  scanf("%d\n", &t);
  for (i = 0; i < t; i++) {
    scanf("%d %d\n", &m, &n);
    sieve(m, n);
  }
  return 0;
}
