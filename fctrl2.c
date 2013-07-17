#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

#define SZ 1000000000

struct big {
  uint32_t x;
  struct big* q;
};

struct big* big_new(uint32_t x) {
  struct big* b = (struct big*)malloc(sizeof(struct big));
  b->x = x;
  b->q = NULL;
  return b;
}

void big_carry(uint64_t x, uint32_t* xt, uint32_t* c) {
  *c = x / (uint64_t)SZ;
  *xt = x % (uint64_t)SZ;
}

struct big* big_add(struct big* b1, struct big* b2) {
  uint32_t c = 0, xt;
  struct big *t = NULL, *p = NULL;
  while (b1 && b2) {
    big_carry(b1->x + b2->x + c, &xt, &c);
    b1 = b1->q;
    b2 = b2->q;
    if (!t) {
      t = p = big_new(xt);
    } else {
      p->q = big_new(xt);
      p = p->q;
    }
  }
  struct big* b = b1;
  if (!b) {
    b = b2;
  }
  while (b) {
    big_carry(b->x + c, &xt, &c);
    b = b->q;
    p->q = big_new(xt);
    p = p->q;
  }
  if (c) {
    p->q = big_new(c);
  }
  return t;
}

struct big* big_mul_single(struct big* b, uint32_t x) {
  uint32_t c = 0, xt;
  struct big *t = NULL, *p = NULL;
  while (b) {
    big_carry(b->x * (uint64_t)x + c, &xt, &c);
    b = b->q;
    if (!t) {
      t = p = big_new(xt);
    } else {
      p->q = big_new(xt);
      p = p->q;
    }
  }
  if (c) {
    p->q = big_new(c);
  }
  return t;
}

struct big* big_mul(struct big* b1, struct big* b2) {
  struct big* car = big_mul_single(b1, b2->x);
  if (!b2->q) {
    return car;
  }
  struct big* cdr = big_new(0);
  cdr->q = big_mul(b1, b2->q);
  return big_add(car, cdr);
}

void big_print(struct big* b) {
  if (b->q == NULL) {
    printf("%d", b->x);
    return;
  }
  big_print(b->q);
  printf("%09d", b->x);
}

void big_println(struct big* b) {
  big_print(b);
  printf("\n");
}

struct big* big_fac(uint32_t n) {
  struct big* t = big_new(1);
  uint32_t i;
  for (i = 2; i <= n; i++) {
    t = big_mul(t, big_new(i));
  }
  return t;
}

int main() {
  int t, i, n;
  scanf("%d\n", &t);
  for (i = 0; i < t; i++) {
    scanf("%d\n", &n);
    big_println(big_fac(n));
  }
  return 0;
}
