#include "stdint.h"

#define BIGSZ 1000000000

struct big {
  uint32_t x;
  struct big* next;
};

extern struct big* big_new(uint32_t x);
extern struct big* big_add(struct big* b1, struct big* b2);
extern struct big* big_mul(struct big* b1, struct big* b2);
extern void big_print(struct big* b);
extern void big_println(struct big* b);
