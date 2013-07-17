#include "stdio.h"
#include "stdlib.h"

void ParseRPNHelper(const char* in, char* out, int* i, int* j) {
  if (in[*i] != '(' && in[*i] != ')') {
    out[(*j)++] = in[(*i)++];
    return;
  }
  (*i)++;
  ParseRPNHelper(in, out, i, j);
  char op = in[(*i)++];
  ParseRPNHelper(in, out, i, j);
  out[(*j)++] = op;
  (*i)++;
}

void ParseRPN(const char* in, char* out) {
  int i = 0, j = 0;
  ParseRPNHelper(in, out, &i, &j);
  out[j++] = '\0';
}

int main() {
  int n, i, sz = 401;
  char expr[sz], rpn[sz];
  scanf("%d\n", &n);
  for (i = 0; i < n; i++) {
    scanf("%s\n", expr);
    ParseRPN(expr, rpn);
    printf("%s\n", rpn);
  }
  return 0;
}
