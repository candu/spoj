#include "stdio.h"
#include "stdlib.h"

#include "big.h"

struct big* big_new(uint32_t x) {
  struct big* b = (struct big*)malloc(sizeof(struct big));
  b->x = x;
  b->next = NULL;
  return b;
}

void big_carry(uint64_t x, uint32_t* xt, uint32_t* c) {
  *c = (uint32_t)(x / (uint64_t)BIGSZ);
  *xt = (uint32_t)(x % (uint64_t)BIGSZ);
}

struct big* big_add(struct big* b1, struct big* b2) {
  uint32_t c = 0, xt;
  struct big *t = NULL, *p = NULL;
  while (b1 && b2) {
    big_carry(b1->x + b2->x + c, &xt, &c);
    b1 = b1->next;
    b2 = b2->next;
    if (!t) {
      t = p = big_new(xt);
    } else {
      p->next = big_new(xt);
      p = p->next;
    }
  }
  struct big* b = b1;
  if (!b) {
    b = b2;
  }
  while (b) {
    big_carry(b->x + c, &xt, &c);
    b = b->next;
    p->next = big_new(xt);
    p = p->next;
  }
  if (c) {
    p->next = big_new(c);
  }
  return t;
}

struct big* big_mul_single(struct big* b, uint32_t x) {
  uint32_t c = 0, xt;
  struct big *t = NULL, *p = NULL;
  while (b) {
    big_carry(b->x * (uint64_t)x + c, &xt, &c);
    b = b->next;
    if (!t) {
      t = p = big_new(xt);
    } else {
      p->next = big_new(xt);
      p = p->next;
    }
  }
  if (c) {
    p->next = big_new(c);
  }
  return t;
}

struct big* big_mul(struct big* b1, struct big* b2) {
  struct big* car = big_mul_single(b1, b2->x);
  if (!b2->next) {
    return car;
  }
  struct big* cdr = big_new(0);
  cdr->next = big_mul(b1, b2->next);
  return big_add(car, cdr);
}

void big_print(struct big* b) {
  if (b->next == NULL) {
    printf("%d", b->x);
    return;
  }
  big_print(b->next);
  printf("%09d", b->x);
}

void big_println(struct big* b) {
  big_print(b);
  printf("\n");
}
