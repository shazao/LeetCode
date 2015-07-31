/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?
*/

// Star: 7.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
  uint32_t rtn;
  uint32_t mask = 0x80000000;
  int i = 0;
  for (; i<32; ++i) {
    if (n & 0x1)
      rtn |= mask;
    else
      rtn &= ~mask;
    n >>= 1;
    mask >>= 1;
  }

  return rtn;
}

void main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Please specify the correct parameter.\n");
    return;
  }

  uint32_t n = atoi(argv[1]);
  printf("Reverse %d binarily is %u.\n", n, reverseBits(n));  // Note 0: "%u".

}
