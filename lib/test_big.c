#include "big.h"

int main() {
  struct big* b1;
  struct big* b2;

  b1 = big_new(1);
  b2 = big_new(2);
  big_println(big_add(b1, b2));

  b1 = big_new(1);
  b2 = big_new(CELL_SIZE - 1);
  big_println(big_add(b1, b2));

  b1 = big_new(1);
  b2 = big_new(CELL_SIZE - 1);
  b2->next = big_new(CELL_SIZE - 1);
  big_println(big_add(b1, b2));

  b1 = big_new(1);
  b1->next = big_new(1);
  b2 = big_new(CELL_SIZE - 1);
  b2->next = big_new(CELL_SIZE - 1);
  big_println(big_add(b1, b2));

  b1 = big_new(2);
  b2 = big_new(3);
  big_println(big_mul(b1, b2));

  b1 = big_new(2);
  b2 = big_new(1);
  b2->next = big_new(1);
  big_println(big_mul(b1, b2));

  b1 = big_new(1);
  b1->next = big_new(2);
  b2 = big_new(3);
  b2->next = big_new(1);
  big_println(big_mul(b1, b2));

  b1 = big_new(100000001);
  b2 = big_new(100000001);
  big_println(big_mul(b1, b2));

  return 0;
}

