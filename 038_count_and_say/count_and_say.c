/* The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string. */

// Star: 7.7.

#include <stdio.h>
#include <stdlib.h>

char * countAndSay(int n) {
  if (n <= 0)
    return 0;

  char * pa = (char *)(malloc(10000*sizeof(char)));
  char * pb = (char *)(malloc(10000*sizeof(char)));
  pa[0] = '1';
  pa[1] = '\0';
  pb[0] = '1';
  pb[1] = '\0';
  char * pr = pa;
  char * pw = pb;
  int i = 1;
  for (; i<n; ++i) {
    if (i%2) {
      pr = pa;
      pw = pb;
    } else {
      pr = pb;
      pw = pa;
    }
    int len = 1;
    while (*pr) {
      while (*pr == *(pr+1)) {
        ++ pr;
        ++ len;
      }
      *pw++ = len+'0';
      //int power = 1;    // Seems no need.
      //int tmp = len;
      //while (tmp /= 10)
      //  power *= 10;
      //while (len) {
      //  *pw++ = len/power + '0';
      //  len %= power;
      //  power /= 10;
      //}
      *pw++ = *pr;  // Note 1: "++".
      len = 1;      // Note 0: Reset length.
      ++ pr;
    }
    *pw = '\0';
  }

  if (i%2) {
    free(pb);
    return pa;
  } else {
    free(pa);
    return pb;
  }
}

void main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Please specify the correct arguments.\n");
    return;
  }

  int n = atoi(argv[1]);
  int i = 1;
  char * s = NULL;
  for (; i<=n; ++i) {
    s = countAndSay(i);
    printf("%s\n", s);
  }

  free(s);
}
