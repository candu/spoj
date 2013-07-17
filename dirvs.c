#include "stdio.h"

#define UNKNOWN -1
#define NO_WALK 0
#define WALK 1

int main() {
  int T, P, Q, R1, C1, R2, C2, i, r, c;
  scanf("%d\n", &T);
  for (i = 0; i < T; i++) {
    // read grid
    scanf("%d %d\n", &P, &Q);
    int Z[P * Q];
    for (r = 0; r < P; r++) {
      for (c = 0; c < Q; c++) {
        scanf("%d", Z + (r * P + c));
      }
      scanf("\n");
    }
    scanf("%d %d %d %d\n", &R1, &C1, &R2, &C2);
    // find path
  }
  return 0;
}
