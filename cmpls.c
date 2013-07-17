#include "stdio.h"

int main() {
  int T, S, C, i, j, k;
  scanf("%d\n", &T);
  for (i = 0; i < T; i++) {
    scanf("%d %d\n", &S, &C);
    int X[S][S + C];
    for (j = 0; j < S; j++) {
      scanf("%d", &(X[0][j]));
    }
    scanf("\n");
    for (j = 1; j < S; j++) {
      for (k = 0; k < S - j; k++) {
        X[j][k] = X[j - 1][k + 1] - X[j - 1][k];
      }
    }
    for (j = 1; j <= C; j++) {
      X[S - 1][j] = X[S - 1][j - 1];
    }
    for (j = S - 2; j >= 0; j--) {
      for (k = S - j; k < S - j + C; k++) {
        X[j][k] = X[j][k - 1] + X[j + 1][k - 1];
      }
    }
    for (j = S; j < S + C - 1; j++) {
      printf("%d ", X[0][j]);
    }
    printf("%d\n", X[0][S + C - 1]);
  }
  return 0;
}
