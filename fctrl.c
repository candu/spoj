#include "stdio.h"

int main() {
  int t, i, n;
  scanf("%d\n", &t);
  for (i = 0; i < t; i++) {
    scanf("%d\n", &n);
    int m = 5, z = 0;
    while (1) {
      int dz = n / m;
      if (dz == 0) {
        break;
      }
      z += dz;
      m *= 5;
    }
    printf("%d\n", z);
  }
  return 0;
}
