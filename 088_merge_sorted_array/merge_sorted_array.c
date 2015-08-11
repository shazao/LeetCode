/* Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively. */

// Star: 7.5.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int * nums1, int m, int * nums2, int n) {

  int mn = m+n;
  int i = 0;
  -- m;       // Note 0: Convert m,n from length to index!
  -- n;
  while (m>=0 && n>=0)
    if (nums1[m] > nums2[n]) 
      nums1[mn-1-i++] = nums1[m--];
    else
      nums1[mn-1-i++] = nums2[n--];

  if (m < 0)
    while (i < mn)
      nums1[mn-1-i++] = nums2[n--];
//  else        // Not needed.
//    while (i < mn)
//      nums1[mn-1-i++] = nums1[m--];
//
}

int main(int argc, char * argv[]) {

  if (argc != 3) {
    printf("Please specify the correct arguments.\n");
    return 0;
  }

  int aa[20];
  int bb[10];
  int m = strlen(argv[1]);
  int n = strlen(argv[2]);

  int i = 0;
  for (; i<m; ++i)
    aa[i] = argv[1][i] - '0';
  for (i=0; i<strlen(argv[2]); ++i)
    bb[i] = argv[2][i] - '0';

  printf("Array a: ");
  for (i=0; i<m; ++i)
    printf("%d ", aa[i]);
  printf("\n");
  printf("Array b: ");
  for (i=0; i<n; ++i)
    printf("%d ", bb[i]);
  printf("\n");

  merge(aa, m, bb, n);
  printf("Merged array: ");
  for (i=0; i<m+n; ++i)
    printf("%d ", aa[i]);
  printf("\n");

  return 0;
}
